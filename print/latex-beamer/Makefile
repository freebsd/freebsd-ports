PORTNAME=	latex-beamer
DISTVERSIONPREFIX=	v
DISTVERSION=	3.71
CATEGORIES=	print

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX class to create a beamer presentation
WWW=		https://github.com/josephwright/beamer/

LICENSE=		GPLv2 LPPL13c
LICENSE_COMB=		dual
LICENSE_FILE_GPLv2=	${WRKSRC}/doc/licenses/gpl-2.0.txt
LICENSE_FILE_LPPL13c=	${WRKSRC}/doc/licenses/lppl-1-3c.txt

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
