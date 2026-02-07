PORTNAME=	libiio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for interfacing with local and remote IIO devices
WWW=		https://github.com/analogdevicesinc/libiio

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libavahi-client.so:net/avahi-app

USES=		cmake:testing gnome iconv localbase
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	analogdevicesinc

CMAKE_TESTING_ON=	WITH_TESTS

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

# unclear how to run tests, see https://github.com/analogdevicesinc/libiio/issues/1028

.include <bsd.port.mk>
