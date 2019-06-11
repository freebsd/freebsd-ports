# Created by: eivind
# $FreeBSD$

PORTNAME=	ydiff
DISTVERSION=	1.1
PORTEPOCH=	1
MASTER_SITES=	LOCAL/mat/ydiff
CATEGORIES=	textproc

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Diff readability enhancer for color terminals

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist concurrent noflavors
USE_GITHUB=
GH_ACCOUNT=	ymattw

NO_ARCH=	yes

PORTDOCS=	CHANGES.rst README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
