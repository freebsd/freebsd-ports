# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	1.5
CATEGORIES=	textproc
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Meta-port for the different versions of the DocBook DTD

RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/catalog:${PORTSDIR}/textproc/docbook-sgml \
		${LOCALBASE}/share/xml/docbook/catalog.xml:${PORTSDIR}/textproc/docbook-xml \
		sdocbook-xml>0:${PORTSDIR}/textproc/sdocbook-xml

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.include <bsd.port.mk>
