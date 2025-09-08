PORTNAME=	pyhanko-cli
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyhanko_cli-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI tools for stamping and signing PDF files
WWW=		https://docs.pyhanko.eu/en/latest/cli-guide/ \
		https://github.com/MatthiasValvekens/pyHanko/tree/master/pkgs/pyhanko-cli \
		https://github.com/MatthiasValvekens/pyHanko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.3:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhanko>=0.29.1:security/py-pyhanko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhanko-certvalidator>=0.27.0:security/py-pyhanko-certvalidator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=4.3:devel/py-tzlocal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
