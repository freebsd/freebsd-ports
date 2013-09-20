# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tickr
PORTVERSION=	0.6.4
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://www.newsrssticker.com/src/ \
		LOCAL/nivit/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	News RSS Ticker

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

REINPLACE_ARGS=	-e 's,%%PREFIX%%,${PREFIX},1' -i.bak

USE_DOS2UNIX=	tickr.h
USE_GNOME=	desktopfileutils gtk20 libxml2
USES=		pkgconfig

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} ${WRKSRC}/${PORTNAME}.desktop ${WRKSRC}/src/tickr/tickr.h

post-install:
	${LOCALBASE}/bin/desktop-file-install \
		--mode=${SHAREMODE} --dir=${DESKTOPDIR} \
		${WRKSRC}/${PORTNAME}.desktop
	-${LOCALBASE}/bin/update-desktop-database

.include <bsd.port.mk>
