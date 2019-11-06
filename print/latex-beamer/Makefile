# $FreeBSD$

PORTNAME=	latex-beamer
PORTVERSION=	3.36
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://bitbucket.org/rivanvx/beamer/get/
DISTNAME=	version-${PORTVERSION:S/./-/}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LaTeX class to create a beamer presentation

BROKEN=		unfetchable

USES=		tar:bz2
USE_TEX=	texmf latex texhash
TEXHASHDIRS=	${TEXMFDIR}
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/rivanvx-beamer-368aa9ba9d38
PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
CLASS_SUBDIRS=	base examples
DOC_SUBDIRS=	AUTHORS ChangeLog FILES INSTALL README TODO doc solutions

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CLASSDIR}
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
