# Created by: Winston Weinert <winstonw@lavabit.com>
# $FreeBSD$

PORTNAME=	roboto-fonts-ttf
PORTVERSION=	20111129
CATEGORIES=	x11-fonts
MASTER_SITES=	http://developer.android.com/design/static/download/
DISTNAME=	Roboto_Hinted_${PORTVERSION}

MAINTAINER=	winstonw@lavabit.com
COMMENT=	The Roboto typeface family

LICENSE=	APACHE20

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_ZIP=	yes

FONTDIR=	lib/X11/fonts/Roboto
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	FONTDIR=${FONTDIR}
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

NO_STAGE=	yes
do-build:
	@cd ${WRKSRC}/ && \
		${LOCALBASE}/bin/mkfontscale && \
		${LOCALBASE}/bin/mkfontdir

do-install:
	${MKDIR} ${PREFIX}/${FONTDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf fonts.* ${PREFIX}/${FONTDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
