# New ports collection makefile for: rsyslog4-snmp
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

COMMENT=	SNMP trap sender for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog4

MNAME=	snmp
LIB_DEPENDS=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp

CONFIGURE_ARGS+=--enable-snmp

PLIST_FILES+=	lib/rsyslog/omsnmp.la \
		lib/rsyslog/omsnmp.so

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/omsnmp/.libs/omsnmp.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/omsnmp/omsnmp.la ${PREFIX}/lib/rsyslog
.include "${MASTERDIR}/Makefile"
