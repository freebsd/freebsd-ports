# New ports collection makefile for:   website
# Date Created:        2003-11-10 10:13:49
# Whom:                Jean-Baptiste Quenot <jb.quenot@caraldi.com>
#
# Based on the docbook-xsl port
#
# $FreeBSD$
#

PORTNAME=	website
PORTVERSION=	2.5.0
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	docbook

MAINTAINER=	jb.quenot@caraldi.com
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

post-extract:
	${FIND} ${WRKSRC} -name '.#*' -delete

do-install:
.ifndef NOPORTDOCS
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${TAR} -cf - . |\
		${TAR} -xf - -C${EXAMPLESDIR})
.endif
	${MKDIR} ${PINSTDIR}
	(cd ${WRKSRC} && ${TAR} -cf - VERSION ${COPYDIRS} |\
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
