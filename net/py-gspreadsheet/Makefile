# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	gspreadsheet
PORTVERSION=	0.3.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Wrapper around Google Spreadsheets to look like csv.DictReader

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:${PORTSDIR}/devel/py-gdata

USE_PYTHON=		2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
