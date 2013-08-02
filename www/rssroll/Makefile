# $FreeBSD$

PORTNAME=	rssroll
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	http://chaosophia.net/downloads/rssroll/ \
		http://ns1.chaosophia.net/downloads/rssroll/

MAINTAINER=	koue@chaosophia.net
COMMENT=	RSS collector in C

LICENSE=	BSD

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		xml2:${PORTSDIR}/textproc/libxml2 \
		sqlite3:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rssroll ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/www/data/rssroll ${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/index.cgi ${PREFIX}/www/cgi-bin/rssroll.cgi
	${INSTALL_DATA} ${WRKSRC}/rssrollrc ${PREFIX}/etc/rssrollrc.sample
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "html css" ${PREFIX}/www/data/rssroll/)
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/cgi-bin/rssroll.cgi ${PREFIX}/www/data/rssroll/

.include <bsd.port.mk>
