# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geeknote
DISTVERSION=	0.2a
CATEGORIES=	www python

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Command line client for Evernote

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}evernote>=1.17:${PORTSDIR}/www/py-evernote \
		${PYTHON_PKGNAMEPREFIX}html2text>0:${PORTSDIR}/textproc/py-html2text \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}markdown2>0:${PORTSDIR}/textproc/py-markdown2 \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}thrift>0:${PORTSDIR}/devel/py-thrift

USES=		dos2unix python:-2.7
USE_GITHUB=	yes
USE_PYTHON=     autoplist distutils
GH_ACCOUNT=	VitaliyRodnenko
GH_COMMIT=	192a0c5
GH_TAGNAME=	${GH_COMMIT}

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
