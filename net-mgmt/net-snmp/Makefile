# New ports collection makefile for:	ucd-snmp
# Version required:			3.6.1
# Date created:				26 June 1996
# Whom:					gpalmer
#
# $Id: Makefile,v 1.24 1999/04/06 19:00:36 fenner Exp $
#

DISTNAME=	ucd-snmp-3.6.1
CATEGORIES=	net
MASTER_SITES= 	ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.or.jp/pub/network/snmp/ucd-snmp/

MAINTAINER=	gpalmer@FreeBSD.ORG

CONFIGURE_ARGS=	--enable-shared

USE_CONFIGURE=	YES
GNU_CONFIGURE=	YES
.if defined(BATCH)
CONFIGURE_ARGS+= --with-defaults --with-sys-contact=nobody@no.where
.else
IS_INTERACTIVE= yes
.endif
CFLAGS=		-g

MAN1=		snmpbulkwalk.1 snmpd.1 snmpdelta.1 snmpget.1 snmpgetnext.1 \
		snmpnetstat.1 snmpset.1 snmpstatus.1 snmptable.1 snmptest.1 \
		snmptranslate.1 snmptrap.1 snmpwalk.1 snmpcmd.1
MAN3=		read_config.3 mib_api.3 snmp_api.3 snmp_sess_api.3
MAN5=		snmp.conf.5 snmp_config.5 snmpd.conf.5 \
		snmptrapd.conf.5 variables.5
MAN8=		snmptrapd.8
BIN=		snmpbulkwalk snmpget snmpgetnext snmpnetstat snmpset \
		snmpstatus snmptest snmptranslate snmptrap snmpwalk
SBIN=		snmpd snmptrapd

STARTUP_FILE=	${PREFIX}/etc/rc.d/snmpd.sh.sample

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
SHLIB_VERSION=3.5
PATCHDIR=patches.aout
.else
SHLIB_VERSION=3
.endif
MAKE_ENV+= SHLIB_VERSION=${SHLIB_VERSION}

post-patch:
	${CP} ${FILESDIR}/freebsd4.h ${WRKSRC}/s

post-install:
	( cd ${PREFIX}/bin && strip ${BIN} )
	( cd ${PREFIX}/sbin && strip ${SBIN} )
	( cd ${PREFIX}/lib && ${LN} -f libsnmp.so.${SHLIB_VERSION} libsnmp.so )
	@${MKDIR} ${PREFIX}/share/examples/ucd-snmp
	@for F in ${WRKSRC}/etc/* ; do \
		${INSTALL_DATA} $$F ${PREFIX}/share/examples/ucd-snmp ; done
	@if [ ! -f ${STARTUP_FILE} ]; then \
		${ECHO} "Creating ${PREFIX}/etc/rc.d/snmpd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${STARTUP_FILE}; \
		${ECHO} "[ -x ${PREFIX}/sbin/snmpd ] && ${PREFIX}/sbin/snmpd && ${ECHO} -n ' snmpd'" >> ${STARTUP_FILE}; \
		chmod 751 ${STARTUP_FILE}; \
	 fi
	${SETENV} OBJFORMAT="${PORTOBJFORMAT}" ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>

CFLAGS=		-g

