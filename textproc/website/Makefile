# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	website
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	SF/docbook/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doctype and stylesheets for making websites

RUN_DEPENDS=	${LOCALBASE}/share/xsl/docbook/catalog:${PORTSDIR}/textproc/docbook-xsl

XMLDIR=		${LOCALBASE}/share/xml
INSTDIR=	share/xsl/website
PINSTDIR=	${PREFIX}/${INSTDIR}
COPYDIRS=	extensions schema tests xsl

PKGINSTALL=	${WRKSRC}/pkg-install
PKGDEINSTALL=	${WRKSRC}/pkg-deinstall

NO_BUILD=	yes
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS=	${XMLDIR}/catalog.ports
CATALOG_XSL=	${WRKSRC}/catalog

DXVERSIONS=	current 2.2 2.3 2.4.0 2.4.1 2.5.0

post-extract:
	${FIND} ${WRKSRC} -name '.#*' -delete

do-install:
.ifndef NOPORTDOCS
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${TAR} -cf - . |\
		${TAR} -xf - -C${EXAMPLESDIR})
.endif
	${XMLCATMGR} -c "${CATALOG_XSL}" create
.for dxversion in ${DXVERSIONS}
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteSystem \
		http://docbook.sourceforge.net/release/website/${dxversion}/xsl \
		"file://${PREFIX}/${INSTDIR}/xsl"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteURI \
		http://docbook.sourceforge.net/release/website/${dxversion}/xsl \
		"file://${PREFIX}/${INSTDIR}/xsl"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteSystem \
		http://docbook.sourceforge.net/release/website/${dxversion}/schema/dtd \
		"file://${PREFIX}/${INSTDIR}/schema/dtd"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteURI \
		http://docbook.sourceforge.net/release/website/${dxversion}/schema/dtd \
		"file://${PREFIX}/${INSTDIR}/schema/dtd"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteSystem \
		http://docbook.sourceforge.net/release/website/${dxversion} \
		"file://${PREFIX}/${INSTDIR}/schema/dtd"
	${XMLCATMGR} -c "${CATALOG_XSL}" add rewriteURI \
		http://docbook.sourceforge.net/release/website/${dxversion} \
		"file://${PREFIX}/${INSTDIR}/schema/dtd"
.endfor
	${MKDIR} ${PINSTDIR}
	(cd ${WRKSRC} && ${TAR} -cf - VERSION catalog ${COPYDIRS} |\
		${TAR} -xf - -C${PINSTDIR})

post-install:
	@${SED} -e 's,@INSTDIR@,${INSTDIR},g ; \
			s,@XMLCATMGR@,${XMLCATMGR},g ; \
			s,@CATALOG_PORTS_XML@,${CATALOG_PORTS},g' \
			< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's,@XMLCATMGR@,${XMLCATMGR},g ; \
			s,@CATALOG_PORTS_XML@,${CATALOG_PORTS},g' \
			< ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SETENV} PKG_PREFIX=${PREFIX} \
			${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
