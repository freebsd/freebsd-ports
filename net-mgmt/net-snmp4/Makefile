# New ports collection makefile for:	ucd-snmp
# Date created:				26 June 1996
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	ucd-snmp
PORTVERSION=	4.1.1
CATEGORIES=	net
MASTER_SITES= 	ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.or.jp/pub/network/snmp/ucd-snmp/

MAINTAINER=	billf@FreeBSD.org

CONFIGURE_ARGS=	--enable-shared
GNU_CONFIGURE=	YES
.if defined(BATCH)
CONFIGURE_ARGS+= --with-defaults --with-sys-contact=nobody@no.where
.else
IS_INTERACTIVE= yes
.endif
USE_GMAKE=	YES
#CFLAGS=		-g

MAN1=		snmpbulkwalk.1 snmpd.1 snmpdelta.1 snmpget.1 snmpgetnext.1 \
		snmpnetstat.1 snmpset.1 snmpstatus.1 snmptable.1 snmptest.1 \
		snmptranslate.1 snmptrap.1 snmpwalk.1 snmpcmd.1 snmpusm.1
MAN3=		read_config.3 mib_api.3 snmp_api.3 snmp_sess_api.3
MAN5=		snmp.conf.5 snmp_config.5 snmpd.conf.5 \
		snmptrapd.conf.5 variables.5
MAN8=		snmptrapd.8
BIN=		snmpbulkwalk snmpget snmpgetnext snmpnetstat snmpset \
		snmpstatus snmptest snmptranslate snmptrap snmpwalk
SBIN=		snmpd snmptrapd

STARTUP_FILE=	${PREFIX}/etc/rc.d/snmpd.sh.sample

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400000
CONFIGURE_ARGS+=	--with-out-mib-modules="ucd-snmp/vmstat_freebsd2 ucd-snmp/memory_freebsd2"
.endif

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
