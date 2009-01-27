# New ports collection makefile for: rsyslog4-relp
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

COMMENT=	RELP input/output module for rsyslog

MNAME=	relp
BUILD_DEPENDS+= pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	relp.0:${PORTSDIR}/devel/librelp

.include "${.CURDIR}/../rsyslog4/bsd.rsyslog.mk"

CONFIGURE_ARGS+=--enable-relp

PLIST_FILES+=	lib/rsyslog/imrelp.la \
		lib/rsyslog/imrelp.so \
		lib/rsyslog/omrelp.la \
		lib/rsyslog/omrelp.so

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/omrelp/.libs/omrelp.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/omrelp/omrelp.la ${PREFIX}/lib/rsyslog
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/imrelp/.libs/imrelp.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/imrelp/imrelp.la ${PREFIX}/lib/rsyslog
.include <bsd.port.mk>
