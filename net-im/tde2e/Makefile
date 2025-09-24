PORTNAME=	tde2e
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.55
CATEGORIES=	net-im devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for building Telegram clients
WWW=		https://github.com/tdlib/td

LICENSE=	BSL

USES=		cmake:testing compiler:c++14-lang gperf readline ssl

CONFLICTS_INSTALL=	tdlib

USE_GITHUB=	yes
GH_ACCOUNT=	tdlib
GH_PROJECT=	td
GH_TAGNAME=	7d257dc # 1.8.55

CMAKE_ON=	TD_INSTALL_STATIC_LIBRARIES TD_E2E_ONLY
CMAKE_OFF=	BUILD_TESTING FREEBSD_BUILD_BENCHMARKS

PLIST_SUB+=	LIBVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e '/hashvar/ s|GITDIR-NOTFOUND|${GH_TAGNAME}|g' \
		${WRKSRC}/CMake/GetGitRevisionDescription.cmake

.include <bsd.port.mk>
