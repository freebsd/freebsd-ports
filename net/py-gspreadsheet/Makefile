# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	gspreadsheet
PORTVERSION=	0.4.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@FreeBSD.org
COMMENT=	Wrapper around Google Spreadsheets to look like csv.DictReader

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:devel/py-gdata
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose

USES=	python:2
USE_PYTHON=	distutils autoplist

PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

regression-test: build
	@cd ${WRKSRC} && nosetests

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
