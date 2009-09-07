# New ports collection makefile for:	rsyslog
# Date created:		9 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rsyslog
PORTVERSION=	2.0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://download.rsyslog.com/rsyslog/

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Enhanced syslog daemon

LIB_DEPENDS=	logging.0:${PORTSDIR}/devel/liblogging

.ifndef PKGNAMESUFFIX
USE_RC_SUBR=	${PORTNAME}d
SUB_FILES=	pkg-message
MAN8=	rfc3195d.8 rklogd.8 rsyslogd.8
MAN5=	rsyslog.conf.5
.endif

DEPRECATED=	Use sysutils/rsyslog3 or sysutils/rsyslog4 instead
EXPIRATION_DATE=	2009-11-07

NO_LATEST_LINK=	yes
CONFLICTS=	rsyslog-[3-4].[0-9]*
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-klogd --disable-static
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PORT_VERBS=	rfc3195d rklogd ${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|<wait.h>|<sys/wait.h>|' ${WRKSRC}/srUtils.c
	@${REINPLACE_CMD} -e '/^rfc3195d_LDADD =/s|$$| -llogging|;s|-ldl||'\
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/lib/rsyslog/|${PREFIX}/lib/rsyslog/|'\
		${WRKSRC}/Makefile.in ${WRKSRC}/syslogd.c
	@${REINPLACE_CMD} -e 's|rs_strerror_r|strerror_r|g' ${WRKSRC}/rfc3195d.c
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${ECHO_CMD} '#include <sys/socket.h>' >> ${WRKSRC}/net.h
	@${ECHO_CMD} '#include <paths.h>' >> ${WRKSRC}/omusrmsg.h
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-configure:
	@${ECHO_CMD} '#define FEATURE_RFC3195 1' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define PATCHLEVEL "0"' >> ${WRKSRC}/config.h

.ifndef PKGNAMESUFFIX
post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/*html ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
