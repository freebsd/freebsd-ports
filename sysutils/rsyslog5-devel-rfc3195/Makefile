# New ports collection makefile for: rsyslog4-snmp
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

COMMENT=	RFC3195 input support for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog4

MNAME=	rfc3195
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS+=	logging.0:${PORTSDIR}/devel/liblogging

CONFIGURE_ARGS+=--enable-rfc3195

PLIST_FILES+=	lib/rsyslog/im3195.la \
		lib/rsyslog/im3195.so

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/im3195/.libs/im3195.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/im3195/im3195.la ${PREFIX}/lib/rsyslog
.include "${MASTERDIR}/Makefile"
