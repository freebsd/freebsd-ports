# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Meta-port for the different versions of the DocBook DTD

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	DB241 DB30 DB31 DB40 DB41 DB42 DB43 DB44 DB45 DB41_XML \
		DB42_XML DB43_XML DB44_XML DB45_XML DB50_XML SDB_XML \
		SGMLCHARENT XMLCHARENT
OPTIONS_DEFAULT=	DB41_XML DB42_XML DB43_XML DB44_XML DB45_XML DB50_XML \
			SGMLCHARENT XMLCHARENT DB41 DB42 DB43 DB44 DB45
DB241_DESC=	DocBook SGML DTD 2.4.1
DB30_DESC=	DocBook SGML DTD 3.0
DB31_DESC=	DocBook SGML DTD 3.1
DB40_DESC=	DocBook SGML DTD 4.0
DB41_DESC=	DocBook SGML DTD 4.1
DB42_DESC=	DocBook SGML DTD 4.2
DB43_DESC=	DocBook SGML DTD 4.3
DB44_DESC=	DocBook SGML DTD 4.4
DB45_DESC=	DocBook SGML DTD 4.5
DB41_XML_DESC=	DocBook XML DTD 4.1
DB42_XML_DESC=	DocBook XML DTD 4.2
DB43_XML_DESC=	DocBook XML DTD 4.3
DB44_XML_DESC=	DocBook XML DTD 4.4
DB45_XML_DESC=	DocBook XML DTD 4.5
DB50_XML_DESC=	DocBook XML 5.0 distribution
SDB_XML_DESC=	Simplified DocBook XML DTD
SGMLCHARENT_DESC=	ISO 8879:1986 character entity sets (SGML)
XMLCHARENT_DESC=	ISO 8879:1986 character entity sets (XML)

DB241_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/2.4.1:${PORTSDIR}/textproc/docbook-241
DB30_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/3.0:${PORTSDIR}/textproc/docbook-300
DB31_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310
DB40_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/4.0:${PORTSDIR}/textproc/docbook-400
DB41_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-410
DB42_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/4.2:${PORTSDIR}/textproc/docbook-420
DB43_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/4.3:${PORTSDIR}/textproc/docbook-430
DB44_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/4.4:${PORTSDIR}/textproc/docbook-440
DB45_RUN_DEPENDS=	${LOCALBASE}/share/sgml/docbook/4.5:${PORTSDIR}/textproc/docbook-450
DB41_XML_RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.1.2:${PORTSDIR}/textproc/docbook-sk
DB42_XML_RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2:${PORTSDIR}/textproc/docbook-xml
DB43_XML_RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.3:${PORTSDIR}/textproc/docbook-xml-430
DB44_XML_RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.4:${PORTSDIR}/textproc/docbook-xml-440
DB45_XML_RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-xml-450
DB50_XML_RUN_DEPENDS=	${LOCALBASE}/share/xml/docbook/5.0:${PORTSDIR}/textproc/docbook-500
SDB_XML_RUN_DEPENDS=	${LOCALBASE}/share/xml/sdocbook/1.1:${PORTSDIR}/textproc/sdocbook-xml
SGMLCHARENT_RUN_DEPENDS=	${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879
XMLCHARENT_RUN_DEPENDS=	${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent

.include <bsd.port.mk>
