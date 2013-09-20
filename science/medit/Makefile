# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	medit
PORTVERSION=	2012.02.05
CATEGORIES=	science graphics
MASTER_SITES=	http://www.ann.jussieu.fr/~frey/ftp/archives/
EXTRACT_SUFX=	.tgz
DISTFILES=	${SOURCETARB} ${LIBTARBALL}
EXTRACT_ONLY=	${SOURCETARB}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Interactive meshes visualization

BUILD_DEPENDS=	${LOCALBASE}/include/cfortran.h:${PORTSDIR}/lang/cfortran

USE_XORG=	x11 xmu xext
USE_GL=		glut
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	${OPSYS}
MAKE_ENV=	WRKSRC="${WRKSRC}" ARCHI=${OPSYS} ARCH=${ARCH} OSREL=${OSREL}
NO_WRKSUBDIR=	yes

LIBVERSION=	${PORTVERSION}
SOURCETARB=	${PORTNAME}.${PORTVERSION}${EXTRACT_SUFX}
LIBTARBALL=	library.${LIBVERSION}${EXTRACT_SUFX}

PLIST_FILES=	bin/${PORTNAME}

. if !defined(NOPORTEXAMPLES)
DISTFILES+=	meshes.tar.gz
EXTRACT_ONLY+=	meshes.tar.gz
MESHES=		DEFAULT.medit ozark.gis part.bb part.mesh thepart.mesh
PLIST_FILES+=	${MESHES:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS=	%%EXAMPLESDIR%%
. endif

NO_STAGE=	yes
post-extract:
	cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${LIBTARBALL} ${EXTRACT_AFTER_ARGS} --exclude ${MAKEFILE}
	${CP} ${FILESDIR}/gttime.c ${WRKSRC}/sources/
.for l in lplib2.c lplib2.h
	${MV} ${WRKSRC}/sources/${l} ${WRKSRC}/sources/${l}.old
.endfor

pre-build:
	${MKDIR} ${WRKSRC}/bin/${ARCH}/${OSREL}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${MESHES:S|^|${WRKSRC}/INRIA.dir/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
