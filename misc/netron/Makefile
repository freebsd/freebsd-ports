PORTNAME=	netron
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.6
CATEGORIES=	misc python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualizer for neural network, deep learning, machine learning models
WWW=		https://netron.app/ \
		https://github.com/lutzroeder/netron

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist noflavors

USE_GITHUB=	yes
GH_ACCOUNT=	lutzroeder

NO_ARCH=	yes

post-extract:
	@${MV} ${WRKSRC}/source ${WRKSRC}/netron

post-patch:
	@${REINPLACE_CMD} -e 's/0\.0\.0/${DISTVERSION}/g' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
