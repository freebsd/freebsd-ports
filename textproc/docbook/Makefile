# New ports collection makefile for:   docbook
# Date created:        7 April 1999
# Whom:                Nik Clayton <nik@freebsd.org>
#
# Based heavily on work by jfieber
#
# $FreeBSD$
#

PORTNAME=	docbook
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Meta-port for the different versions of the DocBook DTD

NO_BUILD=	yes

OPTIONS=	DB241 "DocBook SGML DTD 2.4.1" off \
		DB30 "DocBook SGML DTD 3.0" off \
		DB31 "DocBook SGML DTD 3.1" off \
		DB40 "DocBook SGML DTD 4.0" off \
		DB41 "DocBook SGML DTD 4.1" on \
		DB42 "DocBook SGML DTD 4.2" on \
		DB43 "DocBook SGML DTD 4.3" on \
		DB44 "DocBook SGML DTD 4.4" on \
		DB45 "DocBook SGML DTD 4.5" on \
		DB41_XML "DocBook XML DTD 4.1" on \
		DB42_XML "DocBook XML DTD 4.2" on \
		DB43_XML "DocBook XML DTD 4.3" on \
		DB44_XML "DocBook XML DTD 4.4" on \
		DB45_XML "DocBook XML DTD 4.5" on \
		DB50_XML "DocBook XML 5.0 distribution" on \
		SDB_XML "Simplified DocBook XML DTD" off \
		SGMLCHARENT "ISO 8879:1986 character entity sets (SGML)" on \
		XMLCHARENT "ISO 8879:1986 character entity sets (XML)" on

.include <bsd.port.pre.mk>

.if defined(WITH_DB241)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/2.4.1:${PORTSDIR}/textproc/docbook-241
.endif

.if defined(WITH_DB30)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/3.0:${PORTSDIR}/textproc/docbook-300
.endif

.if defined(WITH_DB31)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/3.1:${PORTSDIR}/textproc/docbook-310
.endif

.if defined(WITH_DB40)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.0:${PORTSDIR}/textproc/docbook-400
.endif

.if defined(WITH_DB41)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-410
.endif

.if defined(WITH_DB42)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.2:${PORTSDIR}/textproc/docbook-420
.endif

.if defined(WITH_DB43)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.3:${PORTSDIR}/textproc/docbook-430
.endif

.if defined(WITH_DB44)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.4:${PORTSDIR}/textproc/docbook-440
.endif

.if defined(WITH_DB45)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.5:${PORTSDIR}/textproc/docbook-450
.endif

.if defined(WITH_DB41_XML)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.1.2:${PORTSDIR}/textproc/docbook-sk
.endif

.if defined(WITH_DB42_XML)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.2:${PORTSDIR}/textproc/docbook-xml
.endif

.if defined(WITH_DB43_XML)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.3:${PORTSDIR}/textproc/docbook-xml-430
.endif

.if defined(WITH_DB44_XML)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.4:${PORTSDIR}/textproc/docbook-xml-440
.endif

.if defined(WITH_DB45_XML)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-xml-450
.endif

.if defined(WITH_DB50_XML)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-500
.endif

.if defined(WITH_SDB_XML)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/sdocbook/1.1:${PORTSDIR}/textproc/sdocbook-xml
.endif

.if defined(WITH_SGMLCHARENT)
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/iso8879:${PORTSDIR}/textproc/iso8879
.endif

.if defined(WITH_XMLCHARENT)
RUN_DEPENDS+=	${LOCALBASE}/share/xml/xmlcharent/catalog:${PORTSDIR}/textproc/xmlcharent
.endif

do-install:
	@${DO_NADA}

.include <bsd.port.post.mk>
