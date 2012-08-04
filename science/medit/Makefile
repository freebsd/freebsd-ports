# New ports collection makefile for:	Medit
# Date created:			Sep 24, 2006
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=	medit
PORTVERSION=	2011.03.06
PORTREVISION=	1
CATEGORIES=	science graphics
MASTER_SITES=	http://www.ann.jussieu.fr/~frey/ftp/archives/
EXTRACT_SUFX=	.tgz
DISTFILES=	${SOURCETARB} ${LIBTARBALL}
EXTRACT_ONLY=	${SOURCETARB}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Interactive meshes visualization

USE_XORG=	x11 xmu xext
USE_GL=		glut
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	${OPSYS}
MAKE_ENV=	WRKSRC="${WRKSRC}" ARCHI=${OPSYS} ARCH=${ARCH} OSREL=${OSREL}
NO_WRKSUBDIR=	yes

# medit-2011.03.06 does not compile with library.2011.03.06
#LIBVERSION=	${PORTVERSION}
LIBVERSION=	2010.05.20
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

post-extract:
	cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${LIBTARBALL} ${EXTRACT_AFTER_ARGS} --exclude ${MAKEFILE}

pre-build:
	${MKDIR} ${WRKSRC}/bin/${ARCH}/${OSREL}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${MESHES:S|^|${WRKSRC}/INRIA.dir/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
