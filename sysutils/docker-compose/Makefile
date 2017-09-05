# $FreeBSD$

PORTNAME=		docker-compose
PORTVERSION=		1.16.1
CATEGORIES=		sysutils python
MASTER_SITES=		CHEESESHOP

MAINTAINER=		lifanov@FreeBSD.org
COMMENT=		Define and run multi-container applications with Docker

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE

RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml \
			${PYTHON_PKGNAMEPREFIX}cached-property>=1.2.0:devel/py-cached-property \
			${PYTHON_PKGNAMEPREFIX}colorama>=0.3.7:devel/py-colorama \
			${PYTHON_PKGNAMEPREFIX}docker>=2.2.1:sysutils/py-docker \
			${PYTHON_PKGNAMEPREFIX}dockerpty>=0.4.1:devel/py-dockerpty \
			${PYTHON_PKGNAMEPREFIX}docopt>=0.6.1:devel/py-docopt \
			${PYTHON_PKGNAMEPREFIX}ipaddress>=1.0.16:net/py-ipaddress \
			${PYTHON_PKGNAMEPREFIX}jsonschema>=2.5.1:devel/py-jsonschema \
			${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests \
			${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six \
			${PYTHON_PKGNAMEPREFIX}texttable>=0.8.4:textproc/py-texttable \
			${PYTHON_PKGNAMEPREFIX}websocket-client>=0.32.0:www/py-websocket-client

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_SUFFIX} < 35
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}backports.ssl_match_hostname>0:security/py-backports.ssl_match_hostname
.endif

.if ${PYTHON_SUFFIX} < 34
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}enum34>0:devel/py-enum34
.endif

.if ${PYTHON_SUFFIX} < 32
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}functools32>0:devel/py-functools32
.endif

.include <bsd.port.post.mk>
