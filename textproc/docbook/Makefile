# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Meta-port for the different versions of the DocBook DTD

NO_BUILD=	yes

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDB241}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/2.4.1:${PORTSDIR}/textproc/docbook-241
.endif

.if ${PORT_OPTIONS:MDB30}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/3.0:${PORTSDIR}/textproc/docbook-300
.endif

.if ${PORT_OPTIONS:MDB31}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310
.endif

.if ${PORT_OPTIONS:MDB40}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.0:${PORTSDIR}/textproc/docbook-400
.endif

.if ${PORT_OPTIONS:MDB41}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-410
.endif

.if ${PORT_OPTIONS:MDB42}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.2:${PORTSDIR}/textproc/docbook-420
.endif

.if ${PORT_OPTIONS:MDB43}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.3:${PORTSDIR}/textproc/docbook-430
.endif

.if ${PORT_OPTIONS:MDB44}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.4:${PORTSDIR}/textproc/docbook-440
.endif

.if ${PORT_OPTIONS:MDB45}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.5:${PORTSDIR}/textproc/docbook-450
.endif

.if ${PORT_OPTIONS:MDB41_XML}
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.1.2:${PORTSDIR}/textproc/docbook-sk
.endif

.if ${PORT_OPTIONS:MDB42_XML}
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.2:${PORTSDIR}/textproc/docbook-xml
.endif

.if ${PORT_OPTIONS:MDB43_XML}
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.3:${PORTSDIR}/textproc/docbook-xml-430
.endif

.if ${PORT_OPTIONS:MDB44_XML}
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.4:${PORTSDIR}/textproc/docbook-xml-440
.endif

.if ${PORT_OPTIONS:MDB45_XML}
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-xml-450
.endif

.if ${PORT_OPTIONS:MDB50_XML}
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/5.0:${PORTSDIR}/textproc/docbook-500
.endif

.if ${PORT_OPTIONS:MSDB_XML}
RUN_DEPENDS+=	${LOCALBASE}/share/xml/sdocbook/1.1:${PORTSDIR}/textproc/sdocbook-xml
.endif

.if ${PORT_OPTIONS:MSGMLCHARENT}
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879
.endif

.if ${PORT_OPTIONS:MXMLCHARENT}
RUN_DEPENDS+=	${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent
.endif

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
