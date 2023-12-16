PORTNAME=	4pane
PORTVERSION=	8.0
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/fourpane/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multi-pane, detailed-list graphical file manager
WWW=		http://www.4pane.co.uk/

LICENSE=	GPLv3

USES=		pkgconfig
USE_WX=		3.0+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config="${WX_CONFIG}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-locale

.include <bsd.port.mk>
