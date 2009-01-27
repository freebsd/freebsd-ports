# New ports collection makefile for: rsyslog4-gssapi
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

COMMENT=	GSS API input/output module for rsyslog

MNAME=	gssapi

.include "${.CURDIR}/../rsyslog4/bsd.rsyslog.mk"
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE= with gssapi module is only supported on FreeBSD 7.x or later
.endif

CONFIGURE_ARGS+=--enable-gssapi-krb5

PLIST_FILES+=	lib/rsyslog/imgssapi.la \
		lib/rsyslog/imgssapi.so \
		lib/rsyslog/lmgssutil.la \
		lib/rsyslog/lmgssutil.so \
		lib/rsyslog/omgssapi.la \
		lib/rsyslog/omgssapi.so

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/omgssapi/.libs/omgssapi.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/omgssapi/omgssapi.la ${PREFIX}/lib/rsyslog
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/imgssapi/.libs/imgssapi.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/imgssapi/imgssapi.la ${PREFIX}/lib/rsyslog
	@${INSTALL_PROGRAM} \
		${WRKSRC}/.libs/lmgssutil.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/lmgssutil.la ${PREFIX}/lib/rsyslog
.include <bsd.port.post.mk>
