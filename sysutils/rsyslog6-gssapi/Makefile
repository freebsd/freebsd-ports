# Created by: Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

COMMENT=	GSS API input/output module for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog6

MNAME=	gssapi

CONFIGURE_ARGS+=--enable-gssapi-krb5

PLIST_FILES+=	lib/rsyslog/imgssapi.la \
		lib/rsyslog/imgssapi.so \
		lib/rsyslog/lmgssutil.la \
		lib/rsyslog/lmgssutil.so \
		lib/rsyslog/omgssapi.la \
		lib/rsyslog/omgssapi.so

NO_STAGE=	yes
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
.include "${MASTERDIR}/Makefile"
