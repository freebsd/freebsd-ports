# New ports collection makefile for:	rsyslog
# Date created:		9 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rsyslog
PORTVERSION=	1.17.2
CATEGORIES=	sysutils
MASTER_SITES=	SF http://download.rsyslog.com/rsyslog/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Enhanced syslog daemon

LIB_DEPENDS=	logging.0:${PORTSDIR}/devel/liblogging

USE_MYSQL=	yes
USE_RC_SUBR=	${PORTNAME}d
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mysql --disable-klogd --mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN8=	rfc3195d.8 rklogd.8 rsyslogd.8
MAN5=	rsyslog.conf.5
PLIST_FILES=	sbin/rfc3195d sbin/rklogd sbin/rsyslogd
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|<wait.h>|<sys/wait.h>|' ${WRKSRC}/srUtils.c
	@${REINPLACE_CMD} -e '/^rfc3195d_LDADD =/s|$$| -llogging|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|' ${WRKSRC}/syslogd.c
	@${ECHO_CMD} '#include <sys/socket.h>' >> ${WRKSRC}/net.h
	@${ECHO_CMD} '#include <paths.h>' >> ${WRKSRC}/omusrmsg.h

post-configure:
	@${ECHO_CMD} '#define FEATURE_RFC3195 1' >> ${WRKSRC}/config.h
	@${ECHO_CMD} '#define PATCHLEVEL "0"' >> ${WRKSRC}/config.h

do-install:
	@cd ${WRKSRC}&&${INSTALL_PROGRAM} rfc3195d rklogd rsyslogd\
		${PREFIX}/sbin/
	@cd ${WRKSRC}&&${INSTALL_MAN} ${MAN5} ${MAN5PREFIX}/man/man5/
	@cd ${WRKSRC}&&${INSTALL_MAN} ${MAN8} ${MAN8PREFIX}/man/man8/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
