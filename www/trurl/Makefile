PORTNAME=	trurl
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.7
CATEGORIES=	www

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Parses, manipulates and outputs URLs and parts of URLs
WWW=		https://curl.se/trurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python:test
USE_GITHUB=	yes
GH_ACCOUNT=	curl

MAKE_ENV=	MANDIR=${PREFIX}/man/man1
ALL_TARGET=	${PORTNAME}
TEST_TARGET=	test

PLIST_FILES=	bin/trurl \
		man/man1/trurl.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s/ *= */ += /' ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/trurl

.include <bsd.port.mk>
