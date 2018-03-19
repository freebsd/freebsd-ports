# $FreeBSD$

PORTNAME=	docker-compose
PORTVERSION=	1.19.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Define and run multi-container applications with Docker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cached-property>=1.2.0:devel/py-cached-property@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.7:devel/py-colorama@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker>=2.7.0:sysutils/py-docker@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dockerpty>=0.4.1:devel/py-dockerpty@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>=0.6.1:devel/py-docopt@${FLAVOR} \
		${PY_ENUM34} \
		${PY_IPADDRESS} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.5.1:devel/py-jsonschema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>=0.9.0:textproc/py-texttable@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0.32.0:www/py-websocket-client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist concurrent optsuffix

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.ssl_match_hostname>0:security/py-backports.ssl_match_hostname@${FLAVOR}
.endif

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}functools32>0:devel/py-functools32@${FLAVOR}
.endif

.include <bsd.port.post.mk>
