# New ports collection makefile for:	gigi
# Date created:				2007-04-29
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	gigi
PORTVERSION=	0.6.0.20070905
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	OpenGL Graphic User Interface Library

LIB_DEPENDS=	IL.1:${PORTSDIR}/graphics/devil \
		boost_python.4:${PORTSDIR}/devel/boost-python \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix="" pkgconfigdir=""
USE_SDL=	sdl
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/GG

#OPTIONS=	OGRE "Enable Ogre (3D engine) support" off

SHLIB_VER=	0
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

.include <bsd.port.pre.mk>

#.if defined(WITH_OGRE)
#LIB_DEPENDS+=	OgreMain.13:${PORTSDIR}/graphics/ogre3d
#PLIST_SUB+=	OGRE=""
#.else
#SCONS_ENV+=	build_ogre_driver=0 build_ogre_ois_plugin=0
#PLIST_SUB+=	OGRE="@comment "
#.endif

post-build:
	@${REINPLACE_CMD} -Ee 's,^(prefix|(lib|include)dir)=,&${PREFIX},' \
		${WRKSRC}/*.pc

do-build:
	@cd ${BUILD_WRKSRC} && \
	${SETENV} ${SCONS_BUILDENV} ktrace -di ${SCONS_BIN} ${SCONS_ENV} ${SCONS_ARGS} \
	${SCONS_TARGET}

do-install:
	${MKDIR} ${PREFIX}/include/GG
	${CP} -R ${WRKSRC}/GG/* ${PREFIX}/include/GG
.for lib in GiGi GiGiSDL
	${INSTALL_PROGRAM} ${WRKSRC}/lib${lib}.so \
		${PREFIX}/lib/lib${lib}.so.${SHLIB_VER}
	cd ${PREFIX}/lib && ${LN} -sf lib${lib}.so.${SHLIB_VER} lib${lib}.so
	${INSTALL_DATA} ${WRKSRC}/${lib}.pc ${PREFIX}/libdata/pkgconfig
.endfor

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export https://${PORTNAME}.svn.sourceforge.net/svnroot/${PORTNAME}/trunk ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.post.mk>
