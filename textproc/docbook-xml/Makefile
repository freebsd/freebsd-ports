# Created by: kuriyama
# $FreeBSD$

PORTNAME=	docbook-xml
PORTVERSION=	4.2
PORTREVISION=	2
MASTER_SITES=	http://www.docbook.org/xml/${PORTVERSION}/ \
		http://www.oasis-open.org/committees/docbook/xml/${PORTVERSION}/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	XML version of the DocBook DTD

NO_ISOCAT=	yes
XML_DTD=	yes
HAS_MANUAL_CATALOG_FILE=	yes

DTD_NAME?=	${PORTNAME:S/-xml//}

PORTDOCS=	README ChangeLog

.include "../../textproc/docbook/bsd.docbook.mk"
.include <bsd.port.mk>
