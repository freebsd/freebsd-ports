PORTNAME=	pysrt
PORTVERSION=	1.1.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SubRip (.srt) subtitle parser and writer
WWW=		https://github.com/byroot/pysrt/

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils nose

NO_ARCH=	yes

.include <bsd.port.mk>
