# Created by: Peter <peter@vereshagin.org>
# $FreeBSD$

PORTNAME=	FCGI-Spawn
PORTVERSION=	0.16.7
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	FastCGI server for CGI-like applications multiprocessing

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-CGI-Fast>=0:www/p5-CGI-Fast \
		p5-Const-Fast>0:devel/p5-Const-Fast \
		p5-FCGI>0:www/p5-FCGI \
		p5-FCGI-ProcManager>0:www/p5-FCGI-ProcManager
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>0:devel/p5-Test-Most \
		p5-Test-Strict>0:devel/p5-Test-Strict

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure
USE_RC_SUBR=	fcgi_spawn

DOCSDIR=	${PREFIX}/share/doc/p5-${PORTNAME}

OPTIONS_DEFINE=	DOCS MYSQL PGSQL
MYSQL_DESC=	MySQL dependency to run on RC start
PGSQL_DESC=	PgSQL dependency to run on RC start

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
# RUN_DEPENDS+=	mysql-server>=0:databases/mysql${MYSQL_VER}-server
SUB_LIST+=	MYSQL=mysql
.	else
SUB_LIST+=	MYSQL=
.endif

.if ${PORT_OPTIONS:MPGSQL}
# RUN_DEPENDS+=	postgresql-server>=0:databases/postgresql${PGSQL_VER}-server
SUB_LIST+=	PGSQL=postgresql
.	else
SUB_LIST+=	PGSQL=
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fcgi_spawn
	${INSTALL_DATA} ${WRKSRC}/fcgi_spawn.conf.sample ${STAGEDIR}${PREFIX}/etc/fcgi_spawn

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
