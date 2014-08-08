# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	thttpd
PORTVERSION=	2.25b
PORTREVISION=	5
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/thttpd/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tiny/turbo/throttling HTTP server

GNU_CONFIGURE=	yes
USES=		gmake	# parallel builds (-jX) are broken with BSD make(1)
USE_RC_SUBR=	thttpd
SUB_FILES=	pkg-message thttpd.conf.sample
SUB_LIST=	WWWOWN=${WWWOWN}

OPTIONS_DEFINE=	SENDFILE
OPTIONS_DEFAULT=	SENDFILE
SENDFILE_DESC=	Use sendfile(2) to serve files

SENDFILE_EXTRA_PATCHES=	${FILESDIR}/extra-patch-config.h

post-patch:
.for f in extras/htpasswd.1 extras/htpasswd.c thttpd.8 extras/Makefile.in
	@${REINPLACE_CMD} -e '/\.htpasswd/!s|htpasswd|thttpdpasswd|g' \
		${WRKSRC}/${f}
.endfor
	@${MV} ${WRKSRC}/extras/htpasswd.1 ${WRKSRC}/extras/thttpdpasswd.1
	@${MV} ${WRKSRC}/extras/htpasswd.c ${WRKSRC}/extras/thttpdpasswd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thttpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/extras/makeweb \
		${WRKSRC}/extras/thttpdpasswd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/extras/syslogtocern \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/data \
		${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/redirect ${WRKSRC}/cgi-src/ssi \
		${WRKSRC}/cgi-src/phf ${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_MAN} ${WRKSRC}/extras/makeweb.1 \
		${WRKSRC}/extras/thttpdpasswd.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/thttpd.8 ${WRKSRC}/cgi-src/redirect.8 \
		${WRKSRC}/cgi-src/ssi.8 ${WRKSRC}/extras/syslogtocern.8 \
			${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKDIR}/thttpd.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
