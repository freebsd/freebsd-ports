PORTNAME=	ryu
PORTVERSION=	4.26
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	akoshibe@gmail.com
COMMENT=	Component-based Software-defined Networking Framework
WWW=		http://osrg.github.io/ryu/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eventlet>0:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>0:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.3.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ovs>0:devel/py-ovs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinyrpc>0:devel/py-tinyrpc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=1.15.0:devel/py-oslo.config@${PY_FLAVOR}

#RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eventlet>0:net/py-eventlet@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}greenlet>=0:devel/py-greenlet@${PY_FLAVOR} \

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	osrg

.include <bsd.port.mk>
