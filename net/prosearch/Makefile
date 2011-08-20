# New ports collection makefile for: prosearch
# Date created:		20 May 2006
# Whom:			Oleg Alexeenkov <proler@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	prosearch
PORTVERSION=	0.19.1
CATEGORIES=	net www
MASTER_SITES=	http://pro.setun.net/search/download/ SF/pro-search/pro-search/${PORTVERSION}

MAINTAINER=	proler@gmail.com
COMMENT=	Powerful file search

USE_BZIP2=	yes
WANT_PERL=	yes
SUB_FILES=	pkg-message
SUB_LIST=	SEARCHDIR=${SEARCHDIR}
NO_BUILD=	yes
SEARCHDIR?=	www/search
PLIST_SUB+=	SEARCHDIR=${SEARCHDIR}

SAMBA_PORT?=	net/samba34

USE_PERL5_RUN=	YES

#todo
# user and group for crawler, nginx
OPTIONS=\
		CRAWLER "With crawler deps (nmap, p5-libwww)" on \
		SAMBA "crawler with SAMBA (file://)" on \
		RSYNC " crawler with RSYNC " off \
		APACH22 "With web server apache2.2+" on \
		APACH20 "With web server apache2.0+" off \
		MOD_PERL2 "With MOD_PERL2" off \
		MOD_FASTCGI "With MOD_FASTCGI" off \
		DB "With database server deps" on \
		MYSQL "mysql" on \
		MARIA "maria (mysql replace)" off \
		PGSQL "postgres" off \
		PGPP "postgres pure Perl connection driver" off \
		SQLITE "sqlite" off \
		SPHINX "sphinx fulltext search engine" off

#		NGINX "With web server deps (NGINX)" off

.include <bsd.port.pre.mk>

RUN_DEPENDS+=\
${SITE_PERL}/lib/abs.pm:${PORTSDIR}/devel/p5-lib-abs

.if defined(WITH_CRAWLER)
RUN_DEPENDS+=\
${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
nmap:${PORTSDIR}/security/nmap \
${SITE_PERL}/Net/DirectConnect.pm:${PORTSDIR}/net-p2p/p5-Net-DirectConnect
.endif

.if defined(WITH_SAMBA)
RUN_DEPENDS+=	smbclient:${PORTSDIR}/${SAMBA_PORT}
.endif

.if defined(WITH_RSYNC)
RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
.endif

.if defined(WITH_APACH22)
USE_APACHE=	22+
.endif

.if defined(WITH_APACH20)
USE_APACHE=	20+
.endif

.if defined(WITH_NGINX)
RUN_DEPENDS+=\
nginx:${PORTSDIR}/www/nginx
.endif

.if defined(WITH_MOD_PERL2)
RUN_DEPENDS+=\
${LOCALBASE}/${APACHEMODDIR}/mod_perl.so:${PORTSDIR}/www/mod_perl2
.endif

.if defined(WITH_MOD_FASTCGI)
RUN_DEPENDS+=\
${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi	\
${SITE_PERL}/${PERL_ARCH}/FCGI.pm:${PORTSDIR}/www/p5-FastCGI
.endif

.if defined(WITH_SPHINX)
WITH_MYSQL=	client	# for dbi
RUN_DEPENDS+=\
searchd:${PORTSDIR}/textproc/sphinxsearch-devel
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	client
RUN_DEPENDS+=\
${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_DB) && defined(WITH_MYSQL)
USE_MYSQL=	server
.endif

.if defined(WITH_MARIA)
RUN_DEPENDS+=\
${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mariadb
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
RUN_DEPENDS+=\
${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if  defined(WITH_PGPP)
RUN_DEPENDS+=\
${SITE_PERL}/DBD/PgPP.pm:${PORTSDIR}/databases/p5-DBD-PgPP
.endif

.if (defined(WITH_PGSQL) || defined(WITH_PGPP)) && defined(WITH_DB)
RUN_DEPENDS+=\
${LOCALBASE}/bin/postgres:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
RUN_DEPENDS+=\
${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

WRKSRC=	${WRKDIR}/search

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${SEARCHDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${SEARCHDIR}
	@${CHMOD} +x ${PREFIX}/${SEARCHDIR}/crawler.pl ${PREFIX}/${SEARCHDIR}/010.search.purge ${PREFIX}/${SEARCHDIR}/*.sh.* ${PREFIX}/${SEARCHDIR}/web/*.*cgi
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${SEARCHDIR:S|^${PREFIX}/|%D/|} >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
