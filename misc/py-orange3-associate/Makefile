PORTNAME=	orange3-associate
DISTVERSION=	1.1.8
PORTREVISION=	2
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Orange 3 add-on: Frequent itemsets and association rules mining
WWW=		https://github.com/biolab/orange3-associate

LICENSE=	GPLv3+

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	biolab

.include <bsd.port.mk>
