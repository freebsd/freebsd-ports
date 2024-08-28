PORTNAME=	trurl
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.15
CATEGORIES=	misc www

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Command line tool for URL parsing and manipulation
WWW=		https://github.com/curl/trurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		gmake localbase:ldflags python:test
USE_GITHUB=	yes
GH_ACCOUNT=	curl

MAKE_ARGS=	PYTHON3=${PYTHON_CMD} \
		TRURL_IGNORE_CURL_CONFIG=1

ALL_TARGET=	${PORTNAME}
INSTALL_TARGET=	install-bin
TEST_TARGET=	test

LDFLAGS+=	-lcurl

PLIST_FILES=	bin/trurl \
		share/man/man1/trurl.1.gz

post-install:
		${INSTALL_MAN} ${FILESDIR}/trurl.1 ${STAGEDIR}${PREFIX}/share/man/man1
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/trurl

.include <bsd.port.mk>
