# New ports collection makefile for:	ucd-snmp
# Version required:			3.2
# Date created:				26 June 1996
# Whom:					gpalmer
#
# $Id: Makefile,v 1.14 1997/11/22 01:27:13 asami Exp $
#

DISTNAME=	ucd-snmp-3.2
CATEGORIES=	net
MASTER_SITES= 	ftp://ftp.ece.ucdavis.edu/pub/snmp/

MAINTAINER=	gpalmer@FreeBSD.ORG

GNU_CONFIGURE=	yes
.if defined(PACKAGE_BUILDING)
CONFIGURE_ARGS=	--with-defaults --with-sys-contact=nobody@no.where
.else
IS_INTERACTIVE= yes
.endif
MAN1=		snmpget.1 snmpset.1 snmpwalk.1 snmpbulkwalk.1 \
		snmpgetnext.1 snmptest.1 snmpnetstat.1 snmptranslate.1 \
		snmptrap.1 snmpstatus.1
MAN3=		snmp_api.3 mib_api.3
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
	@if [ ! -f ${PREFIX}/etc/rc.d/snmpd.sh ]; then \
		echo "Creating ${PREFIX}/etc/rc.d/snmpd.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/snmpd.sh; \
		echo "[ -x /usr/local/sbin/snmpd ] && /usr/local/sbin/snmpd && echo -n ' snmpd'" >> ${PREFIX}/etc/rc.d/snmpd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/snmpd.sh; \
	 fi

.include <bsd.port.mk>
