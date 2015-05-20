# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	thttpd
PORTVERSION=	2.26
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/thttpd/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tiny/turbo/throttling HTTP server with CGI support

LICENSE=	BSD2CLAUSE

USES=		gmake	# parallel builds (-jX) are broken with BSD make(1)
GNU_CONFIGURE=	yes
MAKE_ARGS=	WEBDIR=${WWWDIR}
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message thttpd.conf.sample
SUB_LIST=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	SENDFILE IPREAL INDEXES
OPTIONS_DEFAULT=	SENDFILE IPREAL

SENDFILE_DESC=	Use sendfile(2) to serve files
IPREAL_DESC=	Respect (pass on) "X-Forwarded-For" header
INDEXES_DESC=	Generate index pages for directories

SENDFILE_EXTRA_PATCHES=	${FILESDIR}/extra-patch-config.h
IPREAL_EXTRA_PATCHES=	${FILESDIR}/extra-patch-ip_real

.include <bsd.port.options.mk>

post-patch:
# To avoid conflict with other ports that also install htpasswd(1)
.for f in extras/htpasswd.1 extras/htpasswd.c thttpd.8
	@${REINPLACE_CMD} -e '/\.htpasswd/!s|htpasswd|t&|g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e 's|/var/www|${WWWDIR}|' \
		${WRKSRC}/extras/makeweb.1
.if ! ${PORT_OPTIONS:MINDEXES}
	@${REINPLACE_CMD} -e '/GENERATE_INDEXES/s|.*|/* & */|' \
		${WRKSRC}/config.h
.endif

post-install:
	${INSTALL_DATA} ${WRKDIR}/thttpd.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
