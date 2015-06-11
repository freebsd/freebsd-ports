# $FreeBSD$

PORTNAME=	prosearch
PORTVERSION=	0.19.4
PORTREVISION=	1
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

SAMBA_PORT?=	net/samba41

#todo
# user and group for crawler, nginx
OPTIONS_DEFINE=	CRAWLER SAMBA RSYNC APACHE MOD_PERL2 MOD_FASTCGI \
		DB MYSQL MARIA PGSQL PGPP SQLITE SPHINX
OPTIONS_DEFAULT=	CRAWLER SAMBA APACHE DB MYSQL
CRAWLER_DESC=		With crawler deps (nmap, p5-libwww)
SAMBA_DESC=		crawler with SAMBA (file://)
RSYNC_DESC=		crawler with RSYNC
APACHE_DESC=		With web server apache2.2+
MOD_PERL2_DESC=		With MOD_PERL2
MOD_FASTCGI_DESC=	With MOD_FASTCGI
DB_DESC=		With database server deps
MARIA_DESC=		maria (mysql replace)
PGPP_DESC=		postgres pure Perl connection driver
SPHINX_DESC=		sphinx fulltext search engine

#		NGINX "With web server deps (NGINX)" off

.include <bsd.port.options.mk>

RUN_DEPENDS+=\
p5-lib-abs>=0:${PORTSDIR}/devel/p5-lib-abs

.if ${PORT_OPTIONS:MCRAWLER}
RUN_DEPENDS+=\
p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
p5-URI>=0:${PORTSDIR}/net/p5-URI \
p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
nmap:${PORTSDIR}/security/nmap \
p5-Net-DirectConnect>=0:${PORTSDIR}/net-p2p/p5-Net-DirectConnect
.endif

.if ${PORT_OPTIONS:MSAMBA}
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-smbclient
.endif

.if ${PORT_OPTIONS:MRSYNC}
RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MNGINX}
RUN_DEPENDS+=\
nginx:${PORTSDIR}/www/nginx
.endif

.if ${PORT_OPTIONS:MMOD_PERL2}
RUN_DEPENDS+=\
${LOCALBASE}/${APACHEMODDIR}/mod_perl.so:${PORTSDIR}/www/mod_perl2
.endif

.if ${PORT_OPTIONS:MMOD_FASTCGI}
RUN_DEPENDS+=\
${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi	\
p5-FCGI>=0:${PORTSDIR}/www/p5-FCGI
.endif

.if ${PORT_OPTIONS:MSPHINX}
WITH_MYSQL=	client	# for dbi
RUN_DEPENDS+=\
searchd:${PORTSDIR}/textproc/sphinxsearch-devel
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	client
RUN_DEPENDS+=\
p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MDB} && ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	server
.endif

.if ${PORT_OPTIONS:MMARIA}
RUN_DEPENDS+=\
p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
${LOCALBASE}bin/mysql:${PORTSDIR}/databases/mariadb-client
.endif

.if ${PORT_OPTIONS:MDB} && ${PORT_OPTIONS:MMARIA}
RUN_DEPENDS+=\
${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mariadb-server
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
RUN_DEPENDS+=\
p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MPGPP}
RUN_DEPENDS+=\
p5-DBD-PgPP>=0:${PORTSDIR}/databases/p5-DBD-PgPP
.endif

.if ${PORT_OPTIONS:MPGSQL} || ${PORT_OPTIONS:MPGPP} || ${PORT_OPTIONS:MDB}
USES+=		pgsql
WANT_PGSQL=	client server
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
RUN_DEPENDS+=\
p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

WRKSRC=	${WRKDIR}/search

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SEARCHDIR}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/${SEARCHDIR}/crawler.pl ${STAGEDIR}${PREFIX}/${SEARCHDIR}/010.search.purge ${STAGEDIR}${PREFIX}/${SEARCHDIR}/*.sh.* ${STAGEDIR}${PREFIX}/${SEARCHDIR}/web/*.*cgi

.include <bsd.port.mk>
