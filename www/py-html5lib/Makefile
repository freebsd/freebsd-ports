# Created by: ijliao
# $FreeBSD$

PORTNAME=	html5lib
PORTVERSION=	0.999
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE:master \
		CHEESESHOP:master \
		http://magemana.nl/ports/dist/:test
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python based HTML parser based on the HTML5 spec

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose

OPTIONS_DEFINE=	TEST

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MTEST)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:master \
		${DISTNAME}-testdata${EXTRACT_SUFX}:test
BUILD_DEPENDS+=	${TEST_DEPENDS}
.endif

regression-test: build
	@${ECHO_MSG} "===>  Testing ${PORTNAME} (patience...)"
	@cd ${WRKSRC} && nosetests -q

.if !empty(PORT_OPTIONS:MTEST)
pre-install: regression-test
.endif

.include <bsd.port.mk>
