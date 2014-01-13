# Created by: Julien Laffaye <jlaffaye@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pelican
PORTVERSION=	3.3.0
CATEGORIES=	www textproc

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Static site generator written in Python

RUN_DEPENDS=	rst2html:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}markdown>0:${PORTSDIR}/textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.6:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.4:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}feedgenerator>=1.6:${PORTSDIR}/www/py-feedgenerator \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}blinker>0:${PORTSDIR}/devel/py-blinker \
		${PYTHON_PKGNAMEPREFIX}unidecode>0:${PORTSDIR}/converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six

TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock \

OPTIONS_DEFINE=	TEST
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGVERSION=	3.3
USE_PYDISTUTILS=	easy_install
USE_PYTHON=		yes

USE_GITHUB=		yes
GH_ACCOUNT=	getpelican
GH_COMMIT=	b35ce43

.if ${PORT_OPTIONS:MTEST}
BUILD_DEPENDS:=	${TEST_DEPENDS}
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
