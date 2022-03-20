PORTNAME=	uwebsockets
DISTVERSIONPREFIX=	v
DISTVERSION=	20.12.0
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Web I/O library for the most demanding of applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# libdeflate is optionally needed
RUN_DEPENDS=	libdeflate>0:archivers/libdeflate \
		usockets>0:net/usockets

USES=		compiler:c++17-lang cpe gmake
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	uNetworking
GH_PROJECT=	uWebSockets

NO_BUILD=	yes
NO_ARCH=	yes

pre-install: # workaround for https://github.com/uNetworking/uWebSockets/issues/1236
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/uWebSockets

do-test:
	@cd ${WRKSRC}/tests && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD}

.include <bsd.port.mk>
