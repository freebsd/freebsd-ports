# New ports collection makefile for:	ucd-snmp
# Date created:				26 June 1996
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	ucd-snmp
PORTVERSION=	4.1.2
CATEGORIES=	net
MASTER_SITES= 	ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.or.jp/pub/network/snmp/ucd-snmp/

MAINTAINER=	billf@FreeBSD.org

USE_AUTOCONF=	YES
CONFIGURE_ARGS+= --enable-shared
.if defined(BATCH)
CONFIGURE_ARGS+= --with-defaults --with-sys-contact=nobody@no.where
.else
IS_INTERACTIVE= yes
.endif
USE_GMAKE=	YES

MAN1=		snmpbulkget.1 snmpbulkwalk.1 snmpd.1 snmpdelta.1 snmpget.1 \
		snmpgetnext.1 snmpinform.1 snmpnetstat.1 snmpset.1 \
		snmpstatus.1 snmptable.1 snmptest.1 \
		snmptranslate.1 snmptrap.1 snmpwalk.1 snmpcmd.1 snmpusm.1
MAN3=		default_store.3 read_config.3 mib_api.3 snmp_agent_api.3 \
		snmp_alarm.3 snmp_api.3 snmp_close.3 snmp_free_pdu.3 \
		snmp_open.3 snmp_read.3 snmp_select_info.3 snmp_send.3 \
		snmp_sess_api.3 snmp_sess_async_send.3 snmp_sess_close.3 \
		snmp_sess_error.3 snmp_sess_init.3 snmp_sess_open.3 \
		snmp_sess_read.3 snmp_sess_select_info.3 snmp_sess_send.3 \
		snmp_sess_session.3 snmp_sess_timeout.3 snmp_timeout.3 \
		snmp_trap_api.3
MAN5=		snmp.conf.5 snmp_config.5 snmpd.conf.5 \
		snmptrapd.conf.5 variables.5
MAN8=		snmptrapd.8
BIN=		snmpbulkwalk snmpget snmpgetnext snmpnetstat snmpset \
		snmpstatus snmptest snmptranslate snmptrap snmpwalk
SBIN=		snmpd snmptrapd

STARTUP_FILE=	${PREFIX}/etc/rc.d/snmpd.sh.sample

.include <bsd.port.pre.mk>

SHLIB_VERSION=4
PLIST_SUB= shlib=${SHLIB_VERSION}

post-patch:
	@${CP} ${FILESDIR}/freebsd4.h ${WRKSRC}/s

post-install:
	@( cd ${PREFIX}/bin && strip ${BIN} )
	@( cd ${PREFIX}/sbin && strip ${SBIN} )
	@( cd ${PREFIX}/include/ucd-snmp && ${CHMOD} 644 * )
	@( cd ${PREFIX}/share/snmp/mibs && ${CHMOD} 644 * )
	@( cd ${PREFIX}/lib && ${LN} -f libsnmp.so.${SHLIB_VERSION} libsnmp.so )
	@( cd ${PREFIX}/lib && ${LN} -f libucdmibs.so.${SHLIB_VERSION} libucdmibs.so )
	@( cd ${PREFIX}/lib && ${LN} -f libucdagent.so.${SHLIB_VERSION} libucdagent.so )
	@${MKDIR} ${PREFIX}/share/examples/ucd-snmp
	@for F in ${WRKSRC}/EXAMPLE.conf  ${WRKSRC}/agent/mibgroup/examples/ucdDemoPublic.conf; do \
		${INSTALL_DATA} $$F ${PREFIX}/share/examples/ucd-snmp ; done
	@if [ ! -f ${STARTUP_FILE} ]; then \
		${ECHO} "Creating ${PREFIX}/etc/rc.d/snmpd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${STARTUP_FILE}; \
		${ECHO} "[ -x ${PREFIX}/sbin/snmpd ] && ${PREFIX}/sbin/snmpd && ${ECHO} -n ' snmpd'" >> ${STARTUP_FILE}; \
		${CHMOD} 751 ${STARTUP_FILE}; \
	 fi
	${SETENV} OBJFORMAT="${PORTOBJFORMAT}" ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
