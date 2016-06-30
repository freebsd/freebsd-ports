# $FreeBSD$

PORTNAME=	docbook-xsl-ns
PORTVERSION=	1.78.1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/${PORTNAME}/${PORTVERSION}:src \
		SF/docbook/docbook-xsl-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Namespace-aware DocBook XSLT stylesheets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr
RUN_DEPENDS=	docbook>=0:textproc/docbook \
		xmlcatmgr:textproc/xmlcatmgr

USES=	tar:bzip2
NO_BUILD=	yes
EXTRACT_AFTER_ARGS= --exclude=".*" --exclude="*.sh" --exclude "*.LOG"
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PORTDOCS=	*

INSTDIR=	share/xsl/docbook-ns
DOCSRC=		${WRKDIR}/docbook-xsl-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	docbook-xsl-doc-${PORTVERSION}${EXTRACT_SUFX}:doc

post-extract:
	${RM} ${WRKSRC}/svn-commit.tmp

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${INSTDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${DOCSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
