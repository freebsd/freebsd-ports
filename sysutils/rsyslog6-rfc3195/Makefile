# Created by: Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

COMMENT=	RFC3195 input support for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog6

MNAME=	rfc3195
LIB_DEPENDS+=	logging.0:${PORTSDIR}/devel/liblogging

USES=		pkgconfig

CONFIGURE_ARGS+=--enable-rfc3195

PLIST_FILES+=	lib/rsyslog/im3195.la \
		lib/rsyslog/im3195.so

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/im3195/.libs/im3195.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/im3195/im3195.la ${PREFIX}/lib/rsyslog
.include "${MASTERDIR}/Makefile"
