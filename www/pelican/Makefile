# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pelican
PORTVERSION=	3.2.2
CATEGORIES=	www textproc

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Static blog generator for Pythonistas

RUN_DEPENDS=	rst2html:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}markdown>0:${PORTSDIR}/textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.6:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.4:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}feedgenerator>=1.5:${PORTSDIR}/www/py-feedgenerator \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}blinker>0:${PORTSDIR}/devel/py-blinker \
		${PYTHON_PKGNAMEPREFIX}unidecode>0:${PORTSDIR}/converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock \

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install tools for test suite
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

USE_GITHUB=		yes
USE_PYTHON=		2.7+
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	getpelican
GH_COMMIT=	4d9197d

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
