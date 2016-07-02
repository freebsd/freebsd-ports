# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	thttpd
PORTVERSION=	2.27
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/thttpd/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tiny/turbo/throttling HTTP server with CGI support

LICENSE=	BSD2CLAUSE

USES=		cpe
GNU_CONFIGURE=	yes
MAKE_ARGS=	WEBDIR=${WWWDIR}
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message thttpd.conf.sample
SUB_LIST=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
CPE_VENDOR=	acme

OPTIONS_DEFINE=	SENDFILE IPREAL INDEXES HTACCESS STATS LOG_UNKNOWN FLUSH_LOG
OPTIONS_DEFAULT=	SENDFILE IPREAL STATS FLUSH_LOG

SENDFILE_DESC=	Use sendfile(2) to serve files
IPREAL_DESC=	Respect (pass on) "X-Forwarded-For" header
INDEXES_DESC=	Generate index pages for directories
HTACCESS_DESC=	IP-based authorization (.htaccess) support
STATS_DESC=	Collect internal stats and print to system log
LOG_UNKNOWN_DESC=	Log unknown request headers
FLUSH_LOG_DESC=	fflush() the log file after each request

SENDFILE_EXTRA_PATCHES=	${FILESDIR}/extra-patch-config.h
IPREAL_EXTRA_PATCHES=	${FILESDIR}/extra-patch-ip_real
HTACCESS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-htaccess
LOG_UNKNOWN_EXTRA_PATCHES=	${FILESDIR}/extra-patch-log_unknown_headers

post-patch:
# To avoid conflict with other ports that also install htpasswd(1)
.for f in extras/htpasswd.1 extras/htpasswd.c thttpd.8
	@${REINPLACE_CMD} -e '/\.htpasswd/!s|htpasswd|t&|g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|/var/www|${WWWDIR}|' \
		${WRKSRC}/extras/makeweb.1

post-patch-INDEXES-off:
	@${REINPLACE_CMD} -e '/GENERATE_INDEXES/s|.*|/* & */|' \
		${WRKSRC}/config.h

post-patch-STATS-off:
	@${REINPLACE_CMD} -e '/STATS_TIME/s|.*|/* & */|' \
		${WRKSRC}/config.h

post-patch-FLUSH_LOG-off:
	@${REINPLACE_CMD} -e '/FLUSH_LOG_EVERY_TIME/s|.*|/* & */|' \
		${WRKSRC}/config.h

post-install:
	${INSTALL_DATA} ${WRKDIR}/thttpd.conf.sample ${STAGEDIR}${PREFIX}/etc
	${PRINTF} "/var/log/thttpd.log\t  ${WWWOWN}:${WWWGRP}\t640 7 * @T00\
		J\t/var/run/thttpd.pid\n" > \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/${PORTNAME}.conf

.include <bsd.port.mk>
