# New ports collection makefile for:   docbook-xml
# Date created:        17 January 2002
# Whom:                des
#
# $FreeBSD$
#

PORTNAME=	docbook-xsl
PORTVERSION=	1.68.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	docbook

MAINTAINER=	des@FreeBSD.org
COMMENT=	XSL DocBook stylesheets

RUN_DEPENDS=	${XMLDIR}/docbook/4.2/catalog.xml:${PORTSDIR}/textproc/docbook-xml \
		${XMLDIR}/sdocbook/4.1.2.5/catalog:${PORTSDIR}/textproc/sdocbook-xml

USE_BZIP2=	yes
NO_BUILD=	yes

XMLDIR=		${LOCALBASE}/share/xml
INSTDIR=	share/xsl/docbook
PINSTDIR=	${PREFIX}/${INSTDIR}
COPYDIRS=	common fo extensions html htmlhelp images \
		javahelp lib manpages params template xhtml
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS=	${XMLDIR}/catalog.ports

post-extract:
	${FIND} ${WRKSRC} -name '.#*' -delete

post-configure:
	@${SED} -e 's,@INSTDIR@,${INSTDIR},g ; \
		s,@XMLCATMGR@,${XMLCATMGR},g ; \
		s,@CATALOG_PORTS_XML@,${CATALOG_PORTS},g' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's,@XMLCATMGR@,${XMLCATMGR},g ; \
		s,@CATALOG_PORTS_XML@,${CATALOG_PORTS},g' \
		< ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
do-install:
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${TAR} -cf - . |\
		${TAR} -xf - -C${DOCSDIR})
.endif
	${MKDIR} ${PINSTDIR}
	(cd ${WRKSRC} && ${TAR} -cf - VERSION ${COPYDIRS} |\
		${TAR} -xf - -C${PINSTDIR})

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
