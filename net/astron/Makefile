PORTNAME=	astron
PORTVERSION=	0.0.20200521
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Server Technology for Realtime Object Networking

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libuv.so:devel/libuv \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Astron
GH_PROJECT=	${GH_ACCOUNT}
GH_TAGNAME=	c8ba982

PLIST_FILES=	bin/astrond

.include <bsd.port.mk>
