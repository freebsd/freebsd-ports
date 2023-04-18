PORTNAME=	pyhanko
PORTVERSION=	0.17.2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyHanko-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for stamping and signing PDF files
WWW=		https://github.com/MatthiasValvekens/pyHanko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=3.3.1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhanko-certvalidator>=0.20<0.21:security/py-pyhanko-certvalidator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2020.1,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=6.1:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.24.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=2.1:devel/py-tzlocal@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
