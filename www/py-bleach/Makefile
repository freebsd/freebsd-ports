PORTNAME=	bleach
PORTVERSION=	5.0.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy safelist-based HTML-sanitizing tool

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webencodings>=0:converters/py-webencodings@${PY_FLAVOR}

USES=		cpe python:3.7+ shebangfix
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

CPE_VENDOR=	mozilla

SHEBANG_FILES=	bleach/_vendor/vendor_install.sh

OPTIONS_DEFINE=	CSS
OPTIONS_DEFAULT=CSS
CSS_DESC=	CSS support

CSS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tinycss2>=1.1.0<1.2:textproc/py-tinycss2@${PY_FLAVOR}

.include <bsd.port.mk>
