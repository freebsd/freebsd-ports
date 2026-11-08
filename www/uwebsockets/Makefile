PORTNAME=	uwebsockets
DISTVERSIONPREFIX=	v
DISTVERSION=	20.81.0
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Web I/O library for the most demanding of applications
WWW=		https://github.com/uNetworking/uWebSockets

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
GH_TUPLE=	uNetworking:uSockets:86097c490263ab662d62e8e7b541390bdec7d149:uSockets/uSockets

MAKEFILE=	GNUmakefile

NO_BUILD=	yes
NO_ARCH=	yes

pre-install: # workaround for https://github.com/uNetworking/uWebSockets/issues/1236
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/uWebSockets

post-patch:
	# HttpResponse is a network integration test that hangs in the
	# sandboxed port build environment, so remove it and its uSockets
	# dependency from the default target.
	@${REINPLACE_CMD} -e '/uSockets/d' -e '/HttpResponse/d' \
		${WRKSRC}/tests/Makefile

do-test:
	@cd ${WRKSRC}/tests && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD}

.include <bsd.port.mk>
