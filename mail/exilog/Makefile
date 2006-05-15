# New ports collection makefile for:	exilog
# Date created:				03 Jun 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	exilog
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://duncanthrax.net/exilog/

MAINTAINER=	ler@lerctr.org
COMMENT=	Tool to centralize and visualize Exim logs with a web front end

RUN_DEPENDS=	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask

USE_PERL5=	yes
USE_APACHE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

# Default sql backend
WITH_SQL_BACKEND?=	mysql

.if (${WITH_SQL_BACKEND} == "mysql")
WITH_MYSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.elif (${WITH_SQL_BACKEND} == "postgresql")
WITH_POSTGRESQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.else
BROKEN=	You should specify sql backend using WITH_SQL_BACKEND
.endif

.ifndef WITHOUT_WWWDIR
EXILOGDIR?=	${PREFIX}/www/exilog
.else
EXILOGDIR?=	${PREFIX}/exilog
.endif

.if defined(NO_AGENT)
PLIST_SUB+=	AGENT="@comment "
.else
USE_RC_SUBR=	exilog.sh
PLIST_SUB+=	AGENT=""
.endif

PLIST_SUB+=	EXILOGDIR="${EXILOGDIR:S,^${PREFIX}/,,}"

.if !defined(NOPORTDOCS)
PORTDOC_FILES=	doc/Changelog \
		doc/exilog.txt \
		doc/mysql-db-script.sql \
		doc/pgsql-db-script.sql
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,$$RealBin/exilog.conf,${PREFIX}/etc/exilog.conf,' ${WRKSRC}/exilog_config.pm
	@${REINPLACE_CMD} -e "s,\(use exilog_config\),use lib \'${EXILOGDIR}\'; \1," ${WRKSRC}/exilog_agent.pl
	@${REINPLACE_CMD} -e "s,\(use exilog_config\),use lib \'${EXILOGDIR}\'; \1," ${WRKSRC}/exilog_cleanup.pl

do-install:
	@${MKDIR} ${EXILOGDIR}
	@${MKDIR} ${EXILOGDIR}/icons
	@${CP} ${WRKSRC}/*.pm ${WRKSRC}/*.css ${WRKSRC}/*.js ${EXILOGDIR}
	@${CP} ${WRKSRC}/icons/*  ${EXILOGDIR}/icons

.if !defined(NO_AGENT)
	@${INSTALL_SCRIPT} ${WRKSRC}/exilog_agent.pl ${PREFIX}/sbin
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/exilog_cleanup.pl ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/exilog_cgi.pl ${EXILOGDIR}
	@${CP} ${WRKSRC}/exilog.conf-example ${PREFIX}/etc/exilog.conf-dist
	@${CHMOD} 0600 ${PREFIX}/etc/exilog.conf-dist
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/etc/exilog.conf-dist
	@${CP} ${FILESDIR}/htaccess ${EXILOGDIR}/.htaccess
.if !defined(NO_AGENT)
	@${INSTALL_SCRIPT} ${WRKDIR}/exilog.sh ${PREFIX}/etc/rc.d
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
