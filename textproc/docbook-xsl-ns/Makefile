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
SUB_FILES=	pkg-install
SUB_LIST+=	INSTDIR="${INSTDIR}" \
		XMLCATMGR="${XMLCATMGR}" \
		CATALOG_PORTS="${LOCALBASE}/share/xml/catalog.ports"
PORTDOCS=	*

INSTDIR=	share/xsl/docbook-ns
DOCSRC=		${WRKDIR}/docbook-xsl-${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	docbook-xsl-doc-${PORTVERSION}${EXTRACT_SUFX}:doc
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${INSTDIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${DOCSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
