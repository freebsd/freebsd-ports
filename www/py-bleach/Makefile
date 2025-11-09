PORTNAME=	bleach
PORTVERSION=	6.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy safelist-based HTML-sanitizing tool
WWW=		https://bleach.readthedocs.io/en/latest/ \
		https://github.com/mozilla/bleach

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webencodings>=0:converters/py-webencodings@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CPE_VENDOR=	mozilla

SHEBANG_FILES=	bleach/_vendor/vendor_install.sh

OPTIONS_DEFINE=	CSS
OPTIONS_DEFAULT=CSS
CSS_DESC=	CSS support

CSS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tinycss2>=1.1.0<1.5:textproc/py-tinycss2@${PY_FLAVOR}

.include <bsd.port.mk>
