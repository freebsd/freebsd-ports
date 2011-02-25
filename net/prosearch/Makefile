# New ports collection makefile for: prosearch
# Date created:		20 May 2006
# Whom:			Oleg Alexeenkov <proler@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	prosearch
PORTVERSION=	0.18.3
PORTREVISION=	2
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

#todo
# user and group for crawler
OPTIONS=\
		CRAWLER "With crawler deps" on \
		SAMBA "crawler with SAMBA (file://)" on \
		RSYNC " crawler with RSYNC " off \
		WEB "With web deps (APACHE)" on \
		MOD_PERL2 "With MOD_PERL2" off \
		MOD_FASTCGI "With MOD_FASTCGI" off \
		DB "With database server deps" on \
		MYSQL "mysql" on \
		PGSQL "postgres" off \
		PGPP "postgres pure perl connection" off \
		SQLITE "sqlite" off

.include <bsd.port.pre.mk>

.if defined(WITH_CRAWLER)
RUN_DEPENDS+=\
${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
nmap:${PORTSDIR}/security/nmap
.endif

.if defined(WITH_SAMBA)
RUN_DEPENDS+=	smbclient:${PORTSDIR}/${SAMBA_PORT}
.endif

.if defined(WITH_RSYNC)
RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
.endif

.if defined(WITH_WEB)
USE_APACHE=	2.0+
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

.if defined(WITH_MYSQL)
USE_MYSQL=	client
USE_PERL5_RUN=	YES
RUN_DEPENDS+=
${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_DB) && defined(WITH_MYSQL)
USE_MYSQL=	server
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
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${SEARCHDIR:S|^${PREFIX}/|%D/|} >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
