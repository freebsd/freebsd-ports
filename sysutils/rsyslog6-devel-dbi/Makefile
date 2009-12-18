# New ports collection makefile for: rsyslog4-dbi
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$

COMMENT=	LibDBI output module for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog5

MNAME=	libdbi
LIB_DEPENDS=	dbi.0:${PORTSDIR}/databases/libdbi

CONFIGURE_ARGS+=--enable-libdbi

PLIST_FILES+=	lib/rsyslog/omlibdbi.la \
		lib/rsyslog/omlibdbi.so

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/omlibdbi/.libs/omlibdbi.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/omlibdbi/omlibdbi.la ${PREFIX}/lib/rsyslog

.include "${MASTERDIR}/Makefile"
