# Created by: marcus@FreeBSD.org
# $FreeBSD$

PORTNAME=	docbook-sk
PORTVERSION=	4.1.2
PORTREVISION=	5
DISTNAME=	docbkx${PORTVERSION:S/.//g}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	XML version of the DocBook DTD version controlled for ScrollKeeper

NO_ISOCAT=	yes
XML_DTD=	yes
HAS_MANUAL_CATALOG_FILE=	yes

DTD_NAME?=	${PORTNAME:S/-sk//}

PORTDOCS=	ChangeLog *.txt

.include "../../textproc/docbook/bsd.docbook.mk"
.include <bsd.port.mk>
