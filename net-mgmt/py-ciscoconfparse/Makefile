# $FreeBSD$

PORTNAME=	ciscoconfparse
DISTVERSION=	1.5.4
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parse, audit, query, build and modify Cisco IOS-style configurations

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddr>=2.1.11:devel/py-ipaddr@${PY_FLAVOR}
.endif

do-test:
.if ${PYTHON_REL} < 3200
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs
.else
	# Skip the L4Object_asa_{lt01,lt02,range} tests as "models_asa" is broken in
	# Python 3
	# See also: https://github.com/mpenning/ciscoconfparse/issues/14
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -k 'not _asa_lt and not _asa_range'
.endif

.include <bsd.port.post.mk>
