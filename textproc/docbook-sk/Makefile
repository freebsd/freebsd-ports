# New ports collection makefile for:	DocBook XML for ScrollKeeper
# Date created:		16 January 2003
# Whom:			marcus@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	docbook-sk
PORTVERSION=	4.1.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/xml/${PORTVERSION}/
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
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML}

DOCBOOKDIR=	${PREFIX}/share/xml/${PORTNAME:S/-sk//}/${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

pre-install:
	@[ -d ${DOCBOOKDIR}/ent ] || ${MKDIR} ${DOCBOOKDIR}/ent

do-install:
	for file in `unzip -l ${DISTDIR}/${DISTFILES}|${AWK} '/:[0-9].*[^\/]$$/{print $$4}'`; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${DOCBOOKDIR}/$$file; \
	done

post-install:
	@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${DOCBOOKDIR}/docbook.cat

.include <bsd.port.mk>
