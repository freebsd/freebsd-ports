PORTNAME=	shodan
PORTVERSION=	1.31.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Python library and command-line utility for Shodan
WWW=		https://cli.shodan.io/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click-plugins>=1.0.3:devel/py-click-plugins@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=3.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.2.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tldextract>=2:dns/py-tldextract@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>0:textproc/py-xlsxwriter@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
