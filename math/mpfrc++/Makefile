PORTNAME=	mpfrc++
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.7.2
CATEGORIES=	math devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance C++ interface for MPFR library
WWW=		http://www.holoborodko.com/pavel/mpfr/ \
		https://github.com/advanpix/mpreal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/copying.txt

RUN_DEPENDS=	${PREFIX}/include/mpfr.h:math/mpfr
TEST_DEPENDS=	${PREFIX}/include/mpfr.h:math/mpfr

USE_GITHUB=	yes
GH_ACCOUNT=	advanpix
GH_PROJECT=	mpreal

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/mpreal.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/mpreal.h ${STAGEDIR}${PREFIX}/include/

do-test:
	@${CXX} -o ${WRKDIR}/test \
		-I${PREFIX}/include -I ${STAGEDIR}${PREFIX}/include \
		-L${PREFIX}/lib -lmpfr \
		${WRKSRC}/example/example.cpp && \
	${WRKDIR}/test && \
	${ECHO} "Test succeeded"

.include <bsd.port.mk>
