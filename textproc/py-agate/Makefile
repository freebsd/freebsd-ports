# $FreeBSD$

PORTNAME=	agate
PORTVERSION=	1.6.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Data analysis library optimized for humans

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytimeparse>=1.1.5:devel/py-pytimeparse@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.0:devel/py-babel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>=2.1:devel/py-parsedatetime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.5.4:devel/py-isodate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=1.2.1:textproc/py-python-slugify@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}leather>=0.3.2:graphics/py-leather@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
