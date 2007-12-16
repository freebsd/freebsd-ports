# New ports collection makefile for: prosearch
# Date created:		20 May 2006
# Whom:			Oleg Alexeenkov <proler@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	prosearch
PORTVERSION=	0.17.2
CATEGORIES=	net www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	pro-search
DISTNAME=	pro-search-0.17.2.tar
EXTRACT_SUFX=	.bz2

MAINTAINER=	proler@gmail.com
COMMENT=	Powerful file search

USE_BZIP2=	yes
SUB_FILES=	pkg-message
SUB_LIST=	SEARCHDIR=${SEARCHDIR}
NO_BUILD=	yes
SEARCHDIR?=	www/search
PLIST_SUB+=	SEARCHDIR=${SEARCHDIR}

#todo
# user and group for crawler
OPTIONS=	\
		CRAWLER        	"With crawler deps "	on	\
		SAMBA        	" crawler with SAMBA "	on	\
		RSYNC        	" crawler with RSYNC "	off	\
		DB        	"With database deps "	on	\
		WEB         	"With web deps "	on	\
		MOD_PERL2	"  With MOD_PERL2 "	on

.include <bsd.port.pre.mk>

.if defined(WITH_WEB)
USE_APACHE=	2.0+
.endif

.if defined(WITH_MOD_PERL2)
RUN_DEPENDS+=\
 ${LOCALBASE}/${APACHEMODDIR}/mod_perl.so:${PORTSDIR}/www/mod_perl2
.endif

.if defined(WITH_CRAWLER) || defined(WITH_WEB) || defined(WITH_DB)
USE_MYSQL=	YES
.endif

.if defined(WITH_CRAWLER) || defined(WITH_WEB)
USE_PERL5_RUN=	YES
RUN_DEPENDS+=\
${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_CRAWLER)
RUN_DEPENDS+=\
${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
nmap:${PORTSDIR}/security/nmap

.endif
.if defined(WITH_SAMBA)
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba3
.endif

.if defined(WITH_RSYNC)
RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
.endif

.if defined(WITH_DB)
RUN_DEPENDS+=\
${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql${MYSQL_VER}-server \
mysqlhotcopy:${PORTSDIR}/databases/mysql${MYSQL_VER}-scripts
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
