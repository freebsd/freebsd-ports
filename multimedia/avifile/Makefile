# New ports collection makefile for:   avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	avifile
PORTVERSION=	0.47.1
CATEGORIES=	graphics
MASTER_SITES=	http://divx.euro.ru/
DISTFILES=	avifile-${PORTVERSION}${EXTRACT_SUFX} binaries.zip
EXTRACT_ONLY=	avifile-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	holger@eit.uni-kl.de

LIB_DEPENDS=	qt2.4:${PORTSDIR}/x11-toolkits/qt22 \
		SDL-1.1.2:${PORTSDIR}/devel/sdl-devel
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

ONLY_FOR_ARCHS= i386
USE_GMAKE=	yes
USE_XLIB=	yes
HAS_CONFIGURE=	yes

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
MOC?=		${X11BASE}/bin/moc2

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		MOC="${MOC}"
CONFIGURE_ARGS= --enable-mmx \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-win32-path=${LOCALBASE}/lib/win32

pre-install:
		unzip ${DISTDIR}/binaries.zip -d ${LOCALBASE}/lib/win32
		strip ${WRKSRC}/bin/aviplay ${WRKSRC}/bin/benchmark
.include <bsd.port.mk>
