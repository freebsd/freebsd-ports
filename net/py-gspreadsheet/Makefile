# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	gspreadsheet
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper around Google Spreadsheets to look like csv.DictReader

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>=2.0.14:devel/py-gdata@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && nosetests

.include <bsd.port.mk>
