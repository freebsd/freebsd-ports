# New ports collection makefile for:   slides
# Date Created:        2004-04-29 13:49:33
# Whom:                Jean-Baptiste Quenot <jb.quenot@caraldi.com>
#
# ex:ts=22:sw=22
#
# $FreeBSD$
#
# Based on the textproc/website port
#

PORTNAME=	slides
PORTVERSION=	3.3.1
CATEGORIES=	textproc
MASTER_SITES=	SF/docbook/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doctype and stylesheets for making slides

RUN_DEPENDS=	${LOCALBASE}/share/xsl/docbook/catalog:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.3/catalog.xml:${PORTSDIR}/textproc/docbook-xml-430

XMLDIR=	${LOCALBASE}/share/xml
INSTDIR=	share/xsl/${PORTNAME}
PINSTDIR=	${PREFIX}/${INSTDIR}
COPYDIRS=	browser graphics schema xsl

PKGINSTALL=	${WRKSRC}/pkg-install
PKGDEINSTALL=	${WRKSRC}/pkg-deinstall

NO_BUILD=	yes
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS=	${XMLDIR}/catalog.ports
MYEXAMPLESDIR=	tests
MYDOCSDIR=	doc

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
.ifndef NOPORTDOCS
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/${MYEXAMPLESDIR} && ${TAR} -cf - . |\
	    ${TAR} -xf - -C${EXAMPLESDIR})
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/${MYDOCSDIR} && ${TAR} -cf - . |\
	    ${TAR} -xf - -C${DOCSDIR})
.endif
	${MKDIR} ${PINSTDIR}
	(cd ${WRKSRC} && ${TAR} -cf - VERSION ${COPYDIRS} |\
	    ${TAR} -xf - -C${PINSTDIR})

REPLACE_EXPR=	-e 's,@INSTDIR@,${INSTDIR},g ; \
	    s,@XMLCATMGR@,${XMLCATMGR},g ; \
	    s,@CATALOG_PORTS_XML@,${CATALOG_PORTS},g ; \
	    s,@PORTNAME@,${PORTNAME},g'
post-install:
	@${SED} ${REPLACE_EXPR} < ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} ${REPLACE_EXPR} < ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
