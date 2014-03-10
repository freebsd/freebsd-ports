# Created by: Winston Weinert <winstonw@lavabit.com>
# $FreeBSD$

PORTNAME=	roboto-fonts-ttf
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://developer.android.com/downloads/design/
DISTNAME=	roboto-${PORTVERSION}

MAINTAINER=	winston@ml1.net
COMMENT=	The Roboto typeface family

LICENSE=	APACHE20

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
WRKSRC=		${WRKDIR}/Roboto_v${PORTVERSION}

FONTDIR=	lib/X11/fonts/Roboto
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	FONTDIR=${FONTDIR}
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

do-build:
	@${MV} ${WRKSRC}/Roboto/*.ttf ${WRKSRC}/RobotoCondensed/*.ttf ${WRKSRC}
	@cd ${WRKSRC} && \
		${LOCALBASE}/bin/mkfontscale && \
		${LOCALBASE}/bin/mkfontdir

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf fonts.dir fonts.scale \
		 ${STAGEDIR}${PREFIX}/${FONTDIR}

.include <bsd.port.mk>
