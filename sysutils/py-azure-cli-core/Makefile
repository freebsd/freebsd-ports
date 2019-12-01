# $FreeBSD$

PORTNAME=	azure-cli-core
PORTVERSION=	2.0.77
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Core Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}adal>=1.2:net-mgmt/py-adal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=1.8:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-telemetry>=0:sysutils/py-azure-cli-telemetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanfriendly>=4.7:textproc/py-humanfriendly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}knack>=0.6.2:devel/py-knack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msrest>=0.4.4:net-mgmt/py-msrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msrestazure>=0.6.2:net-mgmt/py-msrestazure@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0.8:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=17.1.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource>=4.0:devel/py-azure-mgmt-resource@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PY_FUTURES}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}antlr4-python2-runtime>=0:devel/py-antlr4-python2-runtime@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}antlr4-python3-runtime>=0:devel/py-antlr4-python3-runtime@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
