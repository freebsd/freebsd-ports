# New ports collection makefile for:	DocBook XML for ScrollKeeper
# Date created:		16 January 2003
# Whom:			marcus@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	docbook-sk
PORTVERSION=	4.1.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/${PORTVERSION}/
DISTNAME=	docbkx${PORTVERSION:S/.//g}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	XML version of the DocBook DTD version controlled for ScrollKeeper

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	DTD_VERSION=${PORTVERSION} \
		XMLCATMGR=${XMLCATMGR} \
		DOCBOOKDIR=${DOCBOOKDIR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML} \
		CATALOG_PORTS_XML=${CATALOG_PORTS_XML}

DOCBOOKDIR=	${PREFIX}/share/xml/${PORTNAME:S/-sk//}/${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

pre-su-install:
	@[ -d ${DOCBOOKDIR}/ent ] || ${MKDIR} ${DOCBOOKDIR}/ent

do-install:
	for file in `${FIND} ${WRKSRC} -type f | ${SED} -e 's|^${WRKSRC}/||' | ${GREP} -v '^\.' | ${SORT}`; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${DOCBOOKDIR}/$$file; \
	done

post-install:
	@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${DOCBOOKDIR}/docbook.cat
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add public "-//OASIS//ELEMENTS DocBook XML Information Pool V4.1.2//EN" file://${DOCBOOKDIR}/dbpoolx.mod
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add public "-//OASIS//DTD DocBook XML V4.1.2//EN" file://${DOCBOOKDIR}/docbookx.dtd
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add public "-//OASIS//ENTITIES DocBook XML Character Entities V4.1.2//EN" file://${DOCBOOKDIR}/dbcentx.mod
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add public "-//OASIS//ENTITIES DocBook XML Notations V4.1.2//EN" file://${DOCBOOKDIR}/dbnotnx.mod
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add public "-//OASIS//ENTITIES DocBook XML Additional General Entities V4.1.2//EN" file://${DOCBOOKDIR}/dbgenent.mod
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add public "-//OASIS//ELEMENTS DocBook XML Document Hierarchy V4.1.2//EN" file://${DOCBOOKDIR}/dbhierx.mod
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add public "-//OASIS//DTD XML Exchange Table Model 19990315//EN" file://${DOCBOOKDIR}/soextblx.dtd
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add public "-//OASIS//DTD DocBook XML CALS Table Model V4.1.2//EN" file://${DOCBOOKDIR}/calstblx.dtd
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add rewriteSystem "http://www.oasis-open.org/docbook/xml/4.1.2" file://${DOCBOOKDIR}
	@${XMLCATMGR} -c ${CATALOG_PORTS_XML} add rewriteURI "http://www.oasis-open.org/docbook/xml/4.1.2" file://${DOCBOOKDIR}

.include <bsd.port.mk>
