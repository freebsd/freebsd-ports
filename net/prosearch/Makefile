PORTNAME=	prosearch
PORTVERSION=	0.19.4
PORTREVISION=	10
CATEGORIES=	net www
MASTER_SITES=	http://pro.setun.net/search/download/ SF/pro-search/pro-search/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful file search

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix tar:bzip2
USE_PERL5=	run
SHEBANG_FILES=	crawler.pl web/index.cgi web/index.fcgi
SUB_FILES=	pkg-message
SUB_LIST=	SEARCHDIR=${SEARCHDIR}
NO_BUILD=	yes
NO_ARCH=	yes
SEARCHDIR?=	www/search
PLIST_SUB+=	SEARCHDIR=${SEARCHDIR} WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

#TODO user and group for crawler
OPTIONS_DEFINE=	CRAWLER SAMBA RSYNC APACHE MOD_PERL2 MOD_FASTCGI \
		DB MYSQL PGSQL PGPP SQLITE
OPTIONS_DEFAULT=	CRAWLER SAMBA APACHE DB MYSQL
CRAWLER_DESC=		With crawler (nmap, p5-libwww)
SAMBA_DESC=		crawler with SAMBA (file://)
RSYNC_DESC=		crawler with RSYNC
APACHE_DESC=		With web server apache2.2+
MOD_PERL2_DESC=		With MOD_PERL2
MOD_FASTCGI_DESC=	With MOD_FASTCGI
DB_DESC=		With both database server and client
PGPP_DESC=		postgres pure Perl connection driver
#NGINX_DESC=		With web server (NGINX)

.include <bsd.port.options.mk>

RUN_DEPENDS+=\
p5-lib-abs>=0:devel/p5-lib-abs

.if ${PORT_OPTIONS:MCRAWLER}
RUN_DEPENDS+=\
p5-libwww>=0:www/p5-libwww \
p5-URI>=0:net/p5-URI \
p5-DBI>=0:databases/p5-DBI \
p5-HTML-Parser>=0:www/p5-HTML-Parser \
nmap:security/nmap \
p5-Net-DirectConnect>=0:net-p2p/p5-Net-DirectConnect
.endif

.if ${PORT_OPTIONS:MSAMBA}
USES+=		samba:run # smbclient
.endif

.if ${PORT_OPTIONS:MRSYNC}
RUN_DEPENDS+=	rsync:net/rsync
.endif

.if ${PORT_OPTIONS:MAPACHE}
USES+=		apache:run,2.2+
.endif

.if ${PORT_OPTIONS:MNGINX}
RUN_DEPENDS+=\
nginx:www/nginx
.endif

.if ${PORT_OPTIONS:MMOD_PERL2}
RUN_DEPENDS+=\
${LOCALBASE}/${APACHEMODDIR}/mod_perl.so:www/mod_perl2
.endif

.if ${PORT_OPTIONS:MMOD_FASTCGI}
RUN_DEPENDS+=\
${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:www/mod_fastcgi	\
p5-FCGI>=0:www/p5-FCGI
.endif

.if ${PORT_OPTIONS:MMYSQL}
USES+=	mysql
RUN_DEPENDS+=\
p5-DBD-mysql>=0:databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MDB} && ${PORT_OPTIONS:MMYSQL}
USES+=	mysql:server
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
RUN_DEPENDS+=\
p5-DBD-Pg>=0:databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MPGPP}
RUN_DEPENDS+=\
p5-DBD-PgPP>=0:databases/p5-DBD-PgPP
.endif

.if ${PORT_OPTIONS:MPGSQL} || ${PORT_OPTIONS:MPGPP} || ${PORT_OPTIONS:MDB}
USES+=		pgsql
WANT_PGSQL=	client server
.endif

.if ${PORT_OPTIONS:MSQLITE}
USES+=	sqlite
RUN_DEPENDS+=\
p5-DBD-SQLite>=0:databases/p5-DBD-SQLite
.endif

WRKSRC=	${WRKDIR}/search

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SEARCHDIR}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/${SEARCHDIR}/crawler.pl ${STAGEDIR}${PREFIX}/${SEARCHDIR}/010.search.purge ${STAGEDIR}${PREFIX}/${SEARCHDIR}/*.sh.* ${STAGEDIR}${PREFIX}/${SEARCHDIR}/web/*.*cgi

.include <bsd.port.mk>
