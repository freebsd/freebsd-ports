#New ports collection makefile for: rsyslog4-gnutls
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

COMMENT=	GNUTLS module for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog4

MNAME=	gnutls
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls

CONFIGURE_ARGS+=--enable-gnutls

PLIST_FILES+=	lib/rsyslog/lmnsd_gtls.la \
		lib/rsyslog/lmnsd_gtls.so

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/runtime/.libs/lmnsd_gtls.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/runtime/lmnsd_gtls.la ${PREFIX}/lib/rsyslog
.include "${MASTERDIR}/Makefile"
