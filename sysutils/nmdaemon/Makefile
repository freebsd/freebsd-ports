PORTNAME=	nmdaemon
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	sysutils

MAINTAINER=	peter@flytrace.com
COMMENT=	FreeBSD network manager daemon
WWW=		https://github.com/Peter2121/nmdaemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libasync++.a:devel/asyncplusplus \
		${LOCALBASE}/lib/libsockpp.a:net/libsockpp

USES=		cmake compiler:c++20-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Peter2121
GH_PROJECT=	nmdaemon

CONFIGURE_ENV=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
