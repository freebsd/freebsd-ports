# New ports collection makefile for:	addons for kde
# Date created:				7 August 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdeaddons
PORTVERSION=	${KDE_VERSION}
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS+=	noatun.0:${PORTSDIR}/multimedia/kdemultimedia3 \
		SDL-1.1.4:${PORTSDIR}/devel/sdl12

WITH_SDL=	yes
USE_KDEBASE_VER=3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
PLIST_SUB+=	RM=${RM}
SDL_CONFIG=	sdl11-config
CONFIGURE_ENV+=	SDL_CONFIG="${LOCALBASE}/bin/${SDL_CONFIG}"

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

pre-configure:
	${FIND} ${WRKSRC} -type f | ${XARGS} ${GREP} -l sdl-config \
		| ${XARGS} ${REINPLACE_CMD} -e "s@sdl-config@${SDL_CONFIG}@g"
	${FIND} ${WRKSRC} | ${XARGS} touch

.include <bsd.port.mk>
