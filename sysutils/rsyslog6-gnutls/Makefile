#New ports collection makefile for: rsyslog4-gnutls
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

PORTREVISION=	1

COMMENT=	GNUTLS module for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog6

MNAME=	gnutls
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls \
		gcrypt.18:${PORTSDIR}/security/libgcrypt

USE_PKGCONFIG=	yes

CONFIGURE_ARGS+=--enable-gnutls

PLIST_FILES+=	lib/rsyslog/lmnsd_gtls.la \
		lib/rsyslog/lmnsd_gtls.so

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/runtime/.libs/lmnsd_gtls.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/runtime/lmnsd_gtls.la ${PREFIX}/lib/rsyslog
.include "${MASTERDIR}/Makefile"
