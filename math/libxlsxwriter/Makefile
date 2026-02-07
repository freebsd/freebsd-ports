PORTNAME=	libxlsxwriter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
CATEGORIES=	math devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	C library for creating Excel XLSX files
WWW=		https://libxlsxwriter.github.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		cmake:testing compiler:c11 localbase:ldflags minizip pathfix \
		pkgconfig python:test ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jmcnamara

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/third_party/md5 \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/third_party/minizip \
			--no-same-owner --no-same-permissions

CMAKE_TESTING_ON=	BUILD_TESTS

CMAKE_ON=	BUILD_SHARED_LIBS \
		USE_OPENSSL_MD5 \
		USE_SYSTEM_MINIZIP

.include <bsd.port.mk>
