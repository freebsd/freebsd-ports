# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	gspreadsheet
PORTVERSION=	0.4.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Wrapper around Google Spreadsheets to look like csv.DictReader

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:${PORTSDIR}/devel/py-gdata
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

regression-test: build
	@cd ${WRKSRC} && nosetests

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
