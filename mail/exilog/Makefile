# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	exilog
PORTVERSION=	0.5
PORTREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	http://duncanthrax.net/exilog/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to centralize and visualize Exim logs with a web front end

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

#RUN_DEPENDS=	p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask

OPTIONS_DEFINE=	DOCS

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	exilog_agent.pl exilog_cgi.pl exilog_cleanup.pl

# Default sql backend
WITH_SQL_BACKEND?=	mysql

.if (${WITH_SQL_BACKEND} == "mysql")
WITH_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
SERVER=		mysql
.elif (${WITH_SQL_BACKEND} == "postgresql")
WITH_POSTGRESQL=	yes
RUN_DEPENDS+=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
SERVER=		postgresql
.else
BROKEN=	You should specify sql backend using WITH_SQL_BACKEND
.endif
SUB_LIST+=	SERVER=${SERVER}
.ifndef WITHOUT_WWWDIR
EXILOGDIR?=	${PREFIX}/www/exilog
.else
EXILOGDIR?=	${PREFIX}/exilog
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_AGENT)
PLIST_SUB+=	AGENT="@comment "
.else
USE_RC_SUBR=	exilog
PLIST_SUB+=	AGENT=""
.endif

PLIST_SUB+=	EXILOGDIR="${EXILOGDIR:S,^${PREFIX}/,,}"

PORTDOC_FILES=	doc/Changelog \
		doc/exilog.txt \
		doc/mysql-db-script.sql \
		doc/pgsql-db-script.sql

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

pre-patch:
	@${REINPLACE_CMD} -e 's,$$RealBin/exilog.conf,${PREFIX}/etc/exilog.conf,' ${WRKSRC}/exilog_config.pm
	@${REINPLACE_CMD} -e "s,\(use exilog_config\),use lib \'${EXILOGDIR}\'; \1," ${WRKSRC}/exilog_agent.pl
	@${REINPLACE_CMD} -e "s,\(use exilog_config\),use lib \'${EXILOGDIR}\'; \1," ${WRKSRC}/exilog_cleanup.pl

do-install:
	@${MKDIR} ${STAGEDIR}${EXILOGDIR} ${STAGEDIR}${EXILOGDIR}/icons
	@${CP} ${WRKSRC}/*.pm ${WRKSRC}/*.css ${WRKSRC}/*.js ${STAGEDIR}${EXILOGDIR}
	@${CP} ${WRKSRC}/icons/* ${STAGEDIR}${EXILOGDIR}/icons
.if !defined(WITHOUT_AGENT)
	@${INSTALL_SCRIPT} ${WRKSRC}/exilog_agent.pl ${STAGEDIR}${PREFIX}/sbin
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/exilog_cleanup.pl ${STAGEDIR}${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/exilog_cgi.pl ${STAGEDIR}${EXILOGDIR}
	@${CP} ${WRKSRC}/exilog.conf-example ${STAGEDIR}${PREFIX}/etc/exilog.conf-dist
	@${CHMOD} 0600 ${STAGEDIR}${PREFIX}/etc/exilog.conf-dist
	@${CP} ${FILESDIR}/htaccess ${STAGEDIR}${EXILOGDIR}/.htaccess
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
