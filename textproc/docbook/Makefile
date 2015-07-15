# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	1.5
CATEGORIES=	textproc

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Meta-port for the different versions of the DocBook DTD

RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/catalog:${PORTSDIR}/textproc/docbook-sgml \
		${LOCALBASE}/share/xml/docbook/catalog.xml:${PORTSDIR}/textproc/docbook-xml \
		sdocbook-xml>0:${PORTSDIR}/textproc/sdocbook-xml

USES=		metaport

.include <bsd.port.mk>
