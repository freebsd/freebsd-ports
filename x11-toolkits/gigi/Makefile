# New ports collection makefile for:	gigi
# Date created:				2007-04-29
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	gigi
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	OpenGL Graphic User Interface Library

LIB_DEPENDS=	IL.1:${PORTSDIR}/graphics/devil \
		boost_filesystem.4:${PORTSDIR}/devel/boost \
		freetype.9:${PORTSDIR}/print/freetype2

BROKEN=		Does not build

USE_BZIP2=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix=""
USE_SDL=	sdl
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/GG

SHLIB_VER=	0
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

post-build:
.for f in GiGi GiGiNet GiGiSDL
	@cd ${WRKSRC} && ${SED} -e \
		's|%(prefix)s|${PREFIX}|; s|%(libdir)s|${PREFIX}/lib|; \
		 s|%(incdir)s|${PREFIX}/include|; \
		 s|%(version)s|${PORTVERSION}|; s|%(gigi_libs)s||; \
		 s|%(boost_include)s||; s|%(gigi_net_libs)s||; \
		 s|%(gigi_sdl_libs)s||; s|%(sdl_include)s||' \
		 ${f}.pc.in > ${f}.pc
.endfor

do-install:
	${MKDIR} ${PREFIX}/include/GG
	${CP} -R ${WRKSRC}/GG/* ${PREFIX}/include/GG
.for lib in GiGi GiGiNet GiGiSDL
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
	svn export https://svn.sourceforge.net/svnroot/${PORTNAME}/trunk ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.mk>
