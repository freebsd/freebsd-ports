# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oauthlib
PORTVERSION=	0.6.0
CATEGORIES=	security net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	RFC-compliant Python implementation of OAuth

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
TEST_DEPENDS=	nosetests:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	idan
GH_COMMIT=	58abd88

PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 300
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}unittest2>0:${PORTSDIR}/devel/py-unittest2
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.post.mk>
