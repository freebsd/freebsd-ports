# ex:ts=8
# Ports collection makefile for:    dhcp
# Date created:         7 Mar 1996
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	isc-dhcp3
PORTVERSION=	3.0.b2.11
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.isc.org/isc/dhcp/
DISTNAME=	dhcp-3.0b2pl${PORTVERSION:S/3.0.b2.//g}

MAINTAINER=	obrien@FreeBSD.org

.if defined(USE_FACILITY)
_USE_FACILITY:=	`${ECHO} ${USE_FACILITY} | ${TR} "[:lower:]" "[:upper:]"`
USE_FACILITY=	${_USE_FACILITY}
.else
USE_FACILITY=	DAEMON
.endif

HAS_CONFIGURE=	yes

MAN3=		dhcpctl.3 omapi.3
MAN5=		dhclient.conf.5 dhclient.leases.5 dhcp-contrib.5 \
		dhcp-eval.5 dhcp-options.5 dhcpd.conf.5 \
		dhcpd.leases.5
MAN8=		dhclient.8 dhclient-script.8 dhcpd.8 dhcrelay.8

pre-fetch:
.if ${USE_FACILITY} == "DAEMON"
	@${ECHO} ""
	@${ECHO} "	You can choose which syslog faciliy by setting LOG_FACILITY to:"
	@${ECHO} "		daemon, local{0-7}"
	@${ECHO} "	'daemon' is the default option if one is not defined."
	@${ECHO} "	Press Control-C and run make clean build LOG_FACILITY=<local{0-7}>,"
	@${ECHO} "	if you wish to use a different logging facility."
	@${ECHO} ""
	@sleep 2
.endif

post-patch:
	@${PERL} -pi.fbsd -e 's.!!PREFIX!!.${PREFIX}.g' ${WRKSRC}/includes/dhcpd.h
	@${PERL} -pi.fbsd -e "s.!!USE_FACILITY!!.${USE_FACILITY}.g" ${WRKSRC}/includes/site.h
	@${PERL} -pi.fbsd -e 's.!!PREFIX!!.${PREFIX}.g' ${WRKSRC}/client/scripts/freebsd
.for MF in relay/Makefile.dist server/Makefile.dist client/Makefile.dist common/Makefile.dist dhcpctl/Makefile.dist minires/Makefile.dist omapip/Makefile.dist 
	@${PERL} -pi.fbsd -e 's|^DEBUG[	 ]*=|DEBUG ?=|g ; s|^CFLAGS[	 ]*=|CFLAGS +=|g' ${WRKSRC}/${MF}
.endfor

post-install:
	${TOUCH} /var/db/dhcpd.leases
.for file in dhclient dhcpd dhcrelay
	if [ -f ${PREFIX}/sbin/${file} ]; then \
		strip ${PREFIX}/sbin/${file}; \
	fi
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/isc-dhcpd.sh.sample  \
		${PREFIX}/etc/rc.d

.include <bsd.port.mk>
