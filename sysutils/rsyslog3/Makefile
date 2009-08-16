# New ports collection makefile for:	rsyslog3
# Date created:		9 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rsyslog
PORTREVISION=	1

COMMENT=	Enhanced syslog daemon

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls

USE_RC_SUBR=	${PORTNAME}d
SUB_FILES=	pkg-message
MAN8=	rsyslogd.8
MAN5=	rsyslog.conf.5

CONFIGURE_ARGS+=--enable-klog --disable-static --enable-mail \
		--enable-imfile --enable-imtemplate --enable-gnutls
.ifdef WITH_DEBUG
CONFIGURE_ARGS+=--enable-rtinst --enable-debug
.endif

PORTSCOUT=	skipv:3.21.10,3.21.9,3.21.8,3.21.7,3.21.6,3.21.5,3.21.4,3.21.3,3.21.2,3.21.1,3.21.0

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/lib/rsyslog/|${PREFIX}/lib/rsyslog/|'\
		${WRKSRC}/tools/syslogd.c
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/*html ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/bsd.rsyslog.mk"
.include <bsd.port.mk>
