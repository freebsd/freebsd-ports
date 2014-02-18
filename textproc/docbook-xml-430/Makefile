# Created by: hrs
# $FreeBSD$

PORTNAME=	docbook-xml
PORTVERSION=	4.3
PORTREVISION=	1
PKGNAMESUFFIX=	-430

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DocBook/XML DTD V4.3, designed for technical documentation

NO_ISOCAT=	yes
XML_DTD=	yes
HAS_MANUAL_CATALOG_FILE=	yes

DTD_SUBDIR?=	${PORTNAME:S/-xml//}

PORTDOCS=	ChangeLog README

.include "../../textproc/docbook/bsd.docbook.mk"
.include <bsd.port.mk>
