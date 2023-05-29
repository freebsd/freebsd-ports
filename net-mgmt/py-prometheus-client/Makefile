PORTNAME=	prometheus-client
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Official Python client for Prometheus
WWW=		https://github.com/prometheus/client_python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=17.9.0:devel/py-twisted@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=17.9.0:devel/py-twisted@${PY_FLAVOR}

USES=	python

USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_PROJECT=	client_python

NO_ARCH=	yes
.include <bsd.port.mk>
