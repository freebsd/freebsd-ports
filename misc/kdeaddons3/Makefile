# New ports collection makefile for:	addons for kde
# Date created:				7 August 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdeaddons
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Additional plugins and scripts for some KDE applications

LIB_DEPENDS+=	noatun.0:${PORTSDIR}/multimedia/kdemultimedia3 \
		kdegames:${PORTSDIR}/games/kdegames3

USE_KDEBASE_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

pre-configure:
	@ ${FIND} ${WRKSRC} -type f | ${XARGS} ${GREP} -l sdl-config \
		| ${XARGS} ${REINPLACE_CMD} -e "s@sdl-config@${SDL_CONFIG}@g"
	${REINPLACE_CMD} -e 's@-pedantic @@g' ${WRKSRC}/configure

post-configure:
	@ ${TOUCH} ${WRKSRC}/configure ${WRKSRC}/config.status \
		${WRKSRC}/config.h.in

.include <bsd.port.mk>
