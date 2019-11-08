# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tickr
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.newsrssticker.com/src/ \
		LOCAL/nivit/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	News RSS Ticker

BROKEN=		unfetchable

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

REINPLACE_ARGS=	-e 's,%%DATADIR%%,${DATADIR},1' -e 's,%%PREFIX%%,${PREFIX},1' -i.bak

DOS2UNIX_GLOB=	tickr.h
USE_GNOME=	gtk20 libxml2
USES=		desktop-file-utils dos2unix gnome libtool pkgconfig

post-patch:
	${REINPLACE_CMD} ${WRKSRC}/${PORTNAME}.desktop ${WRKSRC}/src/tickr/tickr.h

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tickr-url-list ${STAGEDIR}${DATADIR}/tickr-url-list
	${LOCALBASE}/bin/desktop-file-install \
		--mode=${SHAREMODE} --dir=${STAGEDIR}${DESKTOPDIR} \
		${WRKSRC}/${PORTNAME}.desktop

.include <bsd.port.mk>
