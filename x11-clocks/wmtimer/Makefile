# Created by: Patrick Li <pat@databits.net> et al
# $FreeBSD$

PORTNAME=	wmtimer
PORTVERSION=	2.92
PORTREVISION=	11
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.darkops.net/wmtimer/ \
		LOCAL/uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Multi-Function timer dockapp for WindowMaker

WRKSRC=		${WRKDIR}/${DISTNAME}/wmtimer
PORTDOCS=	README
PLIST_FILES=	bin/wmtimer
USES=		gmake pkgconfig
USE_CSTD=	gnu89
USE_XORG=	x11 xau xcomposite xcursor xdamage xdmcp xext xfixes xi \
		xinerama xpm xrandr xrender
USE_GNOME=	gtk20

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtimer ${STAGEDIR}${PREFIX}/bin
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
