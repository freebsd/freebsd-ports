# New ports collection makefile for:	ucd-snmp
# Version required:			3.1.3
# Date created:				26 June 1996
# Whom:					gpalmer
#
# $Id: Makefile,v 1.11 1997/05/17 17:24:59 fenner Exp $
#

DISTNAME=	ucd-snmp-3.1.3
CATEGORIES=	net
MASTER_SITES= 	ftp://ftp.ece.ucdavis.edu/pub/snmp/

MAINTAINER=	gpalmer@FreeBSD.ORG

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=         "does not work for 3.0 now"
.endif

GNU_CONFIGURE=	yes
.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS=	--with-distdefaults
.else
IS_INTERACTIVE= yes
.endif
MAN1=		snmpget.1 snmpset.1 snmpwalk.1 snmpbulkwalk.1 \
		snmpgetnext.1 snmptest.1 snmpnetstat.1 snmptranslate.1 \
		snmpstatus.1
MAN3=		snmp_api.3
MAN5=		variables.5 snmpd.conf.5
MAN8=		snmptrapd.8 snmpd.8

BIN=		snmpbulkwalk snmpget snmpgetnext snmpnetstat \
		snmpset snmpstatus snmptest snmptranslate \
		snmptrap snmptrapd snmpwalk
SBIN=		snmpd

post-install:
	( cd ${PREFIX}/bin; strip ${BIN} )
	( cd ${PREFIX}/sbin; strip ${SBIN} )
	@${MKDIR} ${PREFIX}/share/examples/ucd-snmp
	@for F in ${WRKSRC}/etc/* ; do \
		${INSTALL_DATA} $$F ${PREFIX}/share/examples/ucd-snmp ; done

.include <bsd.port.mk>
