# Created by: eivind
# $FreeBSD$

PORTNAME=	cdiff
PORTVERSION=	0.9.8
PORTEPOCH=	1
MASTER_SITES=	LOCAL/mat/cdiff GH
CATEGORIES=	textproc

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Diff readability enhancer for color terminals

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=
GH_ACCOUNT=	ymattw

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.rst

post-install:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
