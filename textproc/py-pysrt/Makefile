PORTNAME=	pysrt
PORTVERSION=	1.1.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SubRip (.srt) subtitle parser and writer

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils nose

NO_ARCH=	yes

.include <bsd.port.mk>
