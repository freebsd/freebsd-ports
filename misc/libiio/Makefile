PORTNAME=	libiio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for interfacing with local and remote IIO devices

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libavahi-client.so:net/avahi-app

USES=		cmake gnome iconv localbase
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	analogdevicesinc

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
