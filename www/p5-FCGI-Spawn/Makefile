# New ports collection makefile for:	p5-FCGI-Spawn
# Date created:		2007-12-28
# Whom:			Peter <peter@vereshagin.org>
#
# $FreeBSD$
#

PORTNAME=	FCGI-Spawn
PORTVERSION=	0.16.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	peter@vereshagin.org
COMMENT=	FastCGI server for CGI-like applications multiprocessing

RUN_DEPENDS=	${SITE_PERL}/FCGI/ProcManager.pm:${PORTSDIR}/www/p5-FCGI-ProcManager

PERL_CONFIGURE=	yes

USE_RC_SUBR+= fcgi_spawn

MAN3=		FCGI::Spawn.3
MAN1=		fcgi_spawn.1

OPTIONS=  MYSQL   "MySQL dependency to run on RC start"         off \
    PGSQL   "PgSQL dependency to run on RC start"         off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
# RUN_DEPENDS+=	mysql-server>=0:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
SUB_LIST+=	MYSQL=mysql
.	else
SUB_LIST+=	MYSQL=
.endif

.if defined(WITH_PGSQL)
# RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
SUB_LIST+=	PGSQL=postgresql
.	else
SUB_LIST+=	PGSQL=
.endif

post-install:
	${ECHO} ${WITH_MYSQL} ${SUB_LIST}
	@${MKDIR} ${PREFIX}/etc/fcgi_spawn
	@${INSTALL_DATA} ${WRKSRC}/fcgi_spawn.conf.sample ${PREFIX}/etc/fcgi_spawn
	@${MKDIR} ${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/Bugzilla.CGI.pm.fcgi.spawn.patch ${WRKSRC}/CGI.pm.fcgi.spawn.patch \
		${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
