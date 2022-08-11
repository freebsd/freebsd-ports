PORTNAME=	ydiff
DISTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/mat/ydiff

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Diff readability enhancer for color terminals

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_GITHUB=
GH_ACCOUNT=	ymattw
USE_PYTHON=	autoplist concurrent distutils noflavors

NO_ARCH=	yes

PORTDOCS=	CHANGES.rst README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
