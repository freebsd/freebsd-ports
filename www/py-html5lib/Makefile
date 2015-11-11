# Created by: ijliao
# $FreeBSD$

PORTNAME=	html5lib
PORTVERSION=	0.9999999
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://magemana.nl/ports/dist/:test
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python based HTML parser based on the HTML5 spec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose

OPTIONS_DEFINE=	TEST

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MTEST)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-0.999-testdata${EXTRACT_SUFX}:test
BUILD_DEPENDS+=	${TEST_DEPENDS}
.endif

regression-test: build
	@${ECHO_MSG} "===>  Testing ${PORTNAME} (patience...)"
	@cd ${WRKSRC} && nosetests -q

.if !empty(PORT_OPTIONS:MTEST)
pre-install: regression-test
.endif

.include <bsd.port.mk>
