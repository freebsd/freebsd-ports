# $FreeBSD$

PORTNAME=	docbook-xsl-ns
PORTVERSION=	1.79.1
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/docbook-xsl-ns/${PORTVERSION}:src \
		SF/docbook/docbook-xsl-doc/${PORTVERSION}:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Namespace-aware DocBook XSLT stylesheets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr
RUN_DEPENDS=	docbook>=0:textproc/docbook \
		xmlcatmgr:textproc/xmlcatmgr

USES=		tar:bzip2

EXTRACT_AFTER_ARGS=	--exclude '.*' \
			--exclude '*.sh' \
			--exclude '*.LOG' \
			--exclude svn-commit.tmp
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	docbook-xsl-doc-${PORTVERSION}${EXTRACT_SUFX}:doc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsl/docbook-ns
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/xsl/docbook-ns

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/docbook-xsl-${PORTVERSION}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

# maintainer section:

.if defined(MAINTAINER_MODE)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		docbook-xsl-doc-${PORTVERSION}${EXTRACT_SUFX}:doc
.endif

.include <bsd.port.mk>
