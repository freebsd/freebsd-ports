# New ports collection makefile for:	Medit
# Date created:			Sep 24, 2006
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=	medit
PORTVERSION=	2006.09.24
CATEGORIES=	science graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}	\
		http://www.ann.jussieu.fr/~frey/logiciels/:author
MASTER_SITE_SUBDIR=	thierry
EXTRACT_SUFX=	.tgz
DISTFILES=	# See hereunder

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Interactive meshes visualization

.if defined(MAINTAINER_MODE)
DISTFILES+=	${PORTNAME}.${PORTVERSION}${EXTRACT_SUFX}	\
		${PORTNAME}-missing.${PORTVERSION}${EXTRACT_SUFX}
MD5_FILE=	${MASTERDIR}/distinfo.src

USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	${OPSYS}
MAKE_ENV=	WRKSRC="${WRKSRC}" ARCHI=${OPSYS} ARCH=${ARCH} OSREL=${OSREL}

PLIST_FILES=	# nada
MISSING_FILES=	eigenv.c libmesh3.c libmesh3.h

.else
# We are not allowed to distribute the sources.
DISTFILES+=	${PORTNAME}-${ARCH}-${DISTVER}-${PORTVERSION}${EXTRACT_SUFX}
NO_BUILD=	yes
PATCHDIR=	# No patches
ONLY_FOR_ARCHS=	amd64 i386 ia64 sparc64	# Ask the maintainer to add one

PLIST_FILES=	bin/${PORTNAME}

. if !defined(NOPORTDOCS)
DISTFILES+=	meshes.tar.gz:author
MESHES=		DEFAULT.medit ozark.gis part.bb part.mesh thepart.mesh
PLIST_FILES+=	${MESHES:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS=	%%EXAMPLESDIR%%
. endif
.endif

LIB_DEPENDS+=	glut.4:${PORTSDIR}/graphics/libglut

NO_WRKSUBDIR=	yes
USE_GL=		yes

.include <bsd.port.pre.mk>

. if ${OSVERSION} < 601000
.  if ${ARCH} == i386
DISTVER=	4.11
.   if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.   endif
.  else
BROKEN=		no binary available for your platform x version at the moment
.  endif
. else
.  if (${ARCH} == ia64) || (${ARCH} == sparc64)
DISTVER=	6.2
.  else
DISTVER=	6.1
.  endif
. endif

.if defined(MAINTAINER_MODE)

post-extract:
. for mf in ${MISSING_FILES}
.  if !exists(${WRKSRC}/sources/${mf})
	${CP} ${WRKSRC}/${mf} ${WRKSRC}/sources
.  endif
. endfor

pre-build:
	${MKDIR} ${WRKSRC}/bin/${ARCH}/${OSREL}

tarball:
	cd ${WRKSRC} && \
	${TAR} cvfz ${_DISTDIR}${PORTNAME}-${ARCH}-${OSREL}-${PORTVERSION}${EXTRACT_SUFX}\
		bin/${ARCH}/${OSREL}

.else	# !MAINTAINER_MODE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${ARCH}/${DISTVER}/${PORTNAME} ${PREFIX}/bin
. if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${MESHES:S|^|${WRKSRC}/INRIA.dir/|} ${EXAMPLESDIR}
. endif

.endif

.include <bsd.port.post.mk>
