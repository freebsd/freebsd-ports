# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	slides
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doctype and stylesheets for making slides

BUILD_DEPENDS=	xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr
RUN_DEPENDS=	${LOCALBASE}/share/xsl/docbook/catalog:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.3/catalog.xml:${PORTSDIR}/textproc/docbook-xml-430

XMLDIR=		${LOCALBASE}/share/xml
INSTDIR=	share/xsl/slides
PINSTDIR=	${PREFIX}/${INSTDIR}
COPYDIRS=	browser graphics schema xsl

PKGINSTALL=	${WRKSRC}/pkg-install
PKGDEINSTALL=	${WRKSRC}/pkg-deinstall

NO_BUILD=	yes
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS=	${XMLDIR}/catalog.ports
CATALOG_XSL=	${WRKSRC}/catalog
MYEXAMPLESDIR=	tests
MYDOCSDIR=	doc

DXVERSIONS=	3.3.1 3.2.0 3.1.0 3.0.0 3.0b2 3.0b1 2.1b2 2.1b1 2.0a2 2.0a1 \
		current

REPLACE_EXPR=	-e 's,@INSTDIR@,${INSTDIR},g ; \
	    s,@XMLCATMGR@,${XMLCATMGR},g ; \
	    s,@CATALOG_PORTS_XML@,${CATALOG_PORTS},g ; \
	    s,@PORTNAME@,slides,g'

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/${MYEXAMPLESDIR} && ${TAR} -cf - . |\
	    ${TAR} -xf - -C${EXAMPLESDIR})
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/${MYDOCSDIR} && ${TAR} -cf - . |\
	    ${TAR} -xf - -C${DOCSDIR})
.endif
	${XMLCATMGR} -c "${CATALOG_XSL}" create
.for dxversion in ${DXVERSIONS}
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteSystem \
		http://docbook.sourceforge.net/release/slides/${dxversion}/xsl \
		"file://${PINSTDIR}/xsl"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteURI \
		http://docbook.sourceforge.net/release/slides/${dxversion}/xsl \
		"file://${PINSTDIR}/xsl"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteSystem \
		http://docbook.sourceforge.net/release/slides/${dxversion}/schema/dtd \
		"file://${PINSTDIR}/schema/dtd"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteURI \
		http://docbook.sourceforge.net/release/slides/${dxversion}/schema/dtd \
		"file://${PINSTDIR}/schema/dtd"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteSystem \
		http://docbook.sourceforge.net/release/slides/${dxversion} \
		"file://${PINSTDIR}/schema/dtd"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteURI \
		http://docbook.sourceforge.net/release/slides/${dxversion} \
		"file://${PINSTDIR}/schema/dtd"
.endfor
	${MKDIR} ${PINSTDIR}
	(cd ${WRKSRC} && ${TAR} -cf - VERSION catalog ${COPYDIRS} |\
	    ${TAR} -xf - -C${PINSTDIR})

post-install:
	@${SED} ${REPLACE_EXPR} < ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} ${REPLACE_EXPR} < ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
