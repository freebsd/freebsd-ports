PORTNAME=	nmdaemon
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	sysutils

MAINTAINER=	peter@flytrace.com
COMMENT=	FreeBSD network manager daemon
WWW=		https://github.com/Peter2121/nmdaemon

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++20-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Peter2121
GH_PROJECT=	nmdaemon
#GH_TAGNAME=	292f62b

BUILD_DEPENDS=	${LOCALBASE}/lib/libsockpp.a:net/libsockpp \
				${LOCALBASE}/lib/libasync++.a:devel/asyncplusplus

CONFIGURE_ENV=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
