# Created by: KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdocbook-xml
PORTVERSION=	1.1
PORTEPOCH=	2
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/simple/${PORTVERSION}/
DISTNAME=	docbook-simple-${PORTVERSION}

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	"Simplified" DocBook XML DTD

NO_ISOCAT=	yes
XML_DTD=	yes
MANUAL_DOCS=	yes
CATALOG_FILES=	catalog catalog.xml

DTD_NAME=	${PORTNAME:S/-xml//}

.include "../../textproc/docbook/bsd.docbook.mk"
.include <bsd.port.mk>
