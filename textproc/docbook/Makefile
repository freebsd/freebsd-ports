PORTNAME=	docbook
PORTVERSION=	1.5
CATEGORIES=	textproc

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Meta-port for the different versions of the DocBook DTD
WWW=		https://www.oasis-open.org/docbook/

RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/catalog:textproc/docbook-sgml \
		${LOCALBASE}/share/xml/docbook/catalog.xml:textproc/docbook-xml \
		sdocbook-xml>0:textproc/sdocbook-xml

USES=		metaport

.include <bsd.port.mk>
