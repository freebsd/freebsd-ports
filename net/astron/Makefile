PORTNAME=	astron
PORTVERSION=	0.0.20200521
CATEGORIES=	net

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Server Technology for Realtime Object Networking

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libuv.so:devel/libuv \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Astron
GH_PROJECT=	${GH_ACCOUNT}
GH_TAGNAME=	c8ba982

PLIST_FILES=	bin/astrond

OPTIONS_DEFINE=		SOCI
OPTIONS_DEFAULT=	SOCI

SOCI_DESC=		Database support via Soci
SOCI_LIB_DEPENDS=	libsoci_core.so:databases/soci
SOCI_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Soci

.include <bsd.port.mk>
