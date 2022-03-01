PORTNAME=	globalprotect-openconnect
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.4
CATEGORIES=	security

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	OpenConnect GUI for GlobalProtect protocol

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenconnect.so:security/openconnect

USES=		cmake:noninja qt:5
USE_GITHUB=	yes
USE_QT=		buildtools core dbus declarative gui location network printsupport qmake_build webchannel webengine websockets widgets

GH_ACCOUNT=	yuezk
GH_PROJECT=	GlobalProtect-openconnect
GH_TUPLE+=	itay-grudev:SingleApplication:v3.3.0:sa/3rdparty/SingleApplication
GH_TUPLE+=	SergiusTheBest:plog:1.1.5:plog/3rdparty/plog

.include <bsd.port.mk>
