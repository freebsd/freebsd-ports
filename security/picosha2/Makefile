# $FreeBSD$

PORTNAME=	picosha2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-23
DISTVERSIONSUFFIX=	-gb699e6c
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only SHA256 hash generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	okdshin
GH_PROJECT=	PicoSHA2

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/picosha2.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/picosha2.h ${STAGEDIR}${PREFIX}/include

do-test:
	@cd ${WRKSRC}/test && \
		${CXX} -o test test.cpp -I.. && \
		./test && \
		${ECHO} "Tests succeeded"

.include <bsd.port.mk>
