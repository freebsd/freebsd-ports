PORTNAME=	youseedee
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interface to the Unicode Character Database
WWW=		https://github.com/simoncozens/youseedee

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>=0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		UCD>=0:textproc/UCD

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%UCDDIR%%|${LOCALBASE}/share/unicode/ucd|' ${WRKSRC}/lib/youseedee/__init__.py

.include <bsd.port.mk>
