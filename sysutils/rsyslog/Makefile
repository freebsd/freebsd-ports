# New ports collection makefile for:	rsyslog
# Date created:		9 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rsyslog
PORTVERSION=	1.15.0
CATEGORIES=	sysutils
MASTER_SITES=	SF http://download.rsyslog.com/rsyslog/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Enhanced syslog daemon

LIB_DEPENDS=	logging.0:${PORTSDIR}/devel/liblogging

USE_MYSQL=	yes
USE_RC_SUBR=	${PORTNAME}d
MAKE_ARGS=	LIBLOGGING_INC=-I${LOCALBASE}/include \
		LIBLOGGING_BIN=-llogging \
		FEATURE_RFC3195=1 BINDIR=${PREFIX}/sbin MANDIR=${MANPREFIX}/man \
		LPTHREAD=${PTHREAD_LIBS} CC=${CC}
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-L${LOCALBASE}/lib
BUILD_WRKSRC=	${WRKSRC}/freebsd
INSTALL_WRKSRC=	${WRKSRC}/freebsd

MAN8=	rfc3195d.8 rklogd.8 rsyslogd.8
MAN5=	rsyslog.conf.5
PLIST_FILES=	sbin/rfc3195d sbin/rklogd sbin/rsyslogd etc/${PORTNAME}.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|' ${WRKSRC}/syslogd.c
	@${REINPLACE_CMD} -e '/^CFLAGS=/s|=|+=|;s|-O3||;s|-fomit-frame-pointer||;/INSTALL/s|-b |-s |' \
		${WRKSRC}/master.make

post-install:
	@${INSTALL_DATA} ${WRKSRC}/sample.conf ${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
