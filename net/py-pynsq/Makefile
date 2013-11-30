# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pynsq
PORTVERSION=	0.5.1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Official Python client library for NSQ

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>0:${PORTSDIR}/www/py-tornado
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>0:${PORTSDIR}/www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install tools to run test suite
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	bitly
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	b64f3f3

PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
