# $FreeBSD$

PORTNAME=	agate
PORTVERSION=	1.5.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Data analysis library optimized for humans

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pytimeparse>=1.1.5:devel/py-pytimeparse \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.0:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>=2.1:devel/py-parsedatetime \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.5.4:devel/py-isodate \
		${PYTHON_PKGNAMEPREFIX}awesome-slugify>=1.6.5:textproc/py-awesome-slugify \
		${PYTHON_PKGNAMEPREFIX}leather>=0.3.2:graphics/py-leather

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
