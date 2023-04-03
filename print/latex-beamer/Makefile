PORTNAME=	latex-beamer
PORTVERSION=	3.57
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	print

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX class to create a beamer presentation
WWW=		https://github.com/josephwright/beamer

LICENSE=	GPLv2 LPPL13c
LICENSE_COMB=	dual

USES=	tex
USE_GITHUB=	yes
GH_ACCOUNT=	josephwright
GH_PROJECT=	beamer
USE_TEX=	latex texhash texlua

NO_ARCH=	YES
NO_BUILD=	YES

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
CLASS_SUBDIRS=	base examples
DOC_SUBDIRS=	AUTHORS.md CHANGELOG.md README.md doc solutions
TEXHASHDIRS=	${TEXMFDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	${MV} ${WRKSRC}/doc/examples ${WRKSRC}/examples
	${MV} ${WRKSRC}/doc/solutions ${WRKSRC}/solutions
	cd ${WRKSRC} && for d in ${CLASS_SUBDIRS}; do \
		${PAX} -rw $$d ${STAGEDIR}${PREFIX}/${CLASSDIR}; \
	done

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && for d in ${DOC_SUBDIRS}; do \
		${PAX} -rw $$d ${STAGEDIR}${DOCSDIR}; \
	done

.include <bsd.port.mk>
