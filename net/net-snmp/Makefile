# New ports collection makefile for:	ucd-snmp
# Version required:			3.1
# Date created:				26 June 1996
# Whom:					gpalmer
#
# $Id: Makefile,v 1.1.1.1 1996/07/06 08:14:47 gpalmer Exp $
#

DISTNAME=	ucd-snmp-3.1
CATEGORIES+=	net
MASTER_SITES= 	ftp://ftp.ece.ucdavis.edu/pub/snmp/

MAINTAINER=	gpalmer@FreeBSD.ORG

GNU_CONFIGURE=	yes
IS_INTERACTIVE= yes

BIN=		snmpbulkwalk snmpget snmpgetnext snmpnetstat \
		snmpset snmpstatus snmptest snmptranslate \
		snmptrap snmptrapd snmpwalk
SBIN=		snmpd
MAN1=		snmpget.1 snmpset.1 snmpwalk.1 snmpbulkwalk.1 \
		snmpgetnext.1 snmptest.1 snmpnetstat.1 snmptranslate.1 \
		snmpstatus.1
MAN3=		snmp_api.3
MAN5=		variables.5 snmpd.conf.5
MAN8=		snmptrapd.8 snmpd.8

post-install:
	( cd ${PREFIX}/bin; strip ${BIN} )
	( cd ${PREFIX}/sbin; strip ${SBIN} )
.if !defined(NOMANCOMPRESS)
	( cd ${PREFIX}/man/man1; gzip -9nf ${MAN1} )
	( cd ${PREFIX}/man/man3; gzip -9nf ${MAN3} )
	( cd ${PREFIX}/man/man5; gzip -9nf ${MAN5} )
	( cd ${PREFIX}/man/man8; gzip -9nf ${MAN8} )
.endif
	mkdir -p ${PREFIX}/share/examples/ucd-snmp
	( cd ${WRKSRC}/etc; cp * ${PREFIX}/share/examples/ucd-snmp )

.include <bsd.port.mk>
