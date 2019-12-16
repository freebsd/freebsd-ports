# $FreeBSD$

PORTNAME=	latex-beamer
PORTVERSION=	3.57
DISTVERSIONPREFIX=	v
CATEGORIES=	print

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX class to create a beamer presentation

LICENSE=	GPLv2 LPPL13c
LICENSE_COMB=	dual

USE_TEX=	texmf latex texhash texlua
USE_GITHUB=	yes
GH_ACCOUNT=	josephwright
GH_PROJECT=	beamer
TEXHASHDIRS=	${TEXMFDIR}
NO_BUILD=	YES
NO_ARCH=	YES
PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
CLASS_SUBDIRS=	base examples
DOC_SUBDIRS=	AUTHORS.md CHANGELOG.md README.md doc solutions

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CLASSDIR}
	${MV} ${WRKSRC}/doc/examples ${WRKSRC}/examples
	${MV} ${WRKSRC}/doc/solutions ${WRKSRC}/solutions
	cd ${WRKSRC} && for d in ${CLASS_SUBDIRS}; do \
		${PAX} -rw $$d ${STAGEDIR}${PREFIX}/${CLASSDIR}; \
	done
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && for d in ${DOC_SUBDIRS}; do \
		${PAX} -rw $$d ${STAGEDIR}${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
