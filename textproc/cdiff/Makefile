# Created by: eivind
# $FreeBSD$

PORTNAME=	cdiff
DISTVERSION=	1.0-3
DISTVERSIONSUFFIX=	-ga1a33a5
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
USE_PYTHON=	distutils autoplist concurrent optsuffix
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES.rst README.rst

post-install-DOCS-on:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
