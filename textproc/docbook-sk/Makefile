# Created by: marcus@FreeBSD.org
# $FreeBSD$

PORTNAME=	docbook-sk
PORTVERSION=	4.1.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/${PORTVERSION}/
DISTNAME=	docbkx${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.zip

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	XML version of the DocBook DTD version controlled for ScrollKeeper

RUN_DEPENDS=	${XMLCATMGR}:${PORTSDIR}/textproc/xmlcatmgr

NO_BUILD=	yes
EXTRACT_AFTER_ARGS=	-s ,^,${DISTNAME}/,

PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		DOCBOOKDIR=${DOCBOOKDIR:S/${PREFIX}\///} \
		CATALOG_PORTS_XML=${CATALOG_PORTS_XML}

DOCBOOKDIR=	${PREFIX}/share/xml/${PORTNAME:S/-sk//}/${PORTVERSION}
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_XML=	${PREFIX}/share/xml/catalog.ports

do-install:
	@${MKDIR} ${STAGEDIR}${DOCBOOKDIR}/ent
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCBOOKDIR}

.include <bsd.port.mk>
