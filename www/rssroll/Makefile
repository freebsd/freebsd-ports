# $FreeBSD$

PORTNAME=	rssroll
PORTVERSION=	0.4.1
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	RSS collector in C

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	koue

GNU_CONFIGURE=	yes

PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rssroll ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/data/rssroll ${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/index.cgi ${STAGEDIR}${PREFIX}/www/cgi-bin/rssroll.cgi
	${INSTALL_DATA} ${WRKSRC}/rssrollrc ${STAGEDIR}${PREFIX}/etc/rssrollrc.sample
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "html css" ${STAGEDIR}${PREFIX}/www/data/rssroll/)

.include <bsd.port.mk>
