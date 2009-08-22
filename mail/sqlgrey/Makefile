# New ports collection makefile for:    sqlgrey
# Date created:				17 Feb 2005
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	sqlgrey
PORTVERSION=	1.7.6
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.7%20%28devel%29/${PORTVERSION}

MAINTAINER=	chifeng@gmail.com
COMMENT=	Greylisting policy server for Postfix using an SQL backend

RUN_DEPENDS=	${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser

USE_PERL5_RUN=	yes
USE_RC_SUBR=	sqlgrey.sh
USE_BZIP2=	yes
NO_BUILD=	yes

ETCFILES=	clients_fqdn_whitelist clients_ip_whitelist dyn_fqdn.regexp smtp_server.regexp sqlgrey.conf
SGY_USERNAME?=	sqlgrey
SGY_GROUPNAME?=	${SGY_USERNAME}
ETCDIR?=	etc/sqlgrey

SUB_FILES=	pkg-install
MY_SUB_LIST=	ETCDIR=${ETCDIR} ETCFILES="${ETCFILES}" USER=${SGY_USERNAME} GROUP=${SGY_GROUPNAME} PERL=${PERL}
SUB_LIST+=	${MY_SUB_LIST}
PLIST_SUB=	TOUCH=${TOUCH} ${MY_SUB_LIST}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}

MAN1=	sqlgrey.1

.if !defined(NOPORTDOCS)
PORTDOCS=	Changelog FAQ HOWTO README TODO
.endif

OPTIONS=	PGSQL "PostgreSQL backend" off \
		MYSQL "MySQL backend" off \
		SQLITE "SQLite backend" off \
		STATS "Depend on Date::Calc for logstats.pl script" off

.include <bsd.port.pre.mk>

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_SQLITE)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

.if defined(WITH_STATS)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's-#!/usr/bin/perl-#!${PERL}-' -e 's!/etc/sqlgrey!${PREFIX}/${ETCDIR}!g' ${WRKSRC}/sqlgrey

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sqlgrey-logstats.pl ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/sqlgrey ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/update_sqlgrey_config ${PREFIX}/sbin
	@cd ${WRKSRC} && perldoc -u sqlgrey | pod2man sqlgrey > ${MANPREFIX}/man/man1/sqlgrey.1
	@${MKDIR} ${PREFIX}/${ETCDIR}
.for i in ${ETCFILES}
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/${ETCDIR}/${i}.dist
	@[ "${i}" = "dyn_fqdn.regexp" ] || [ "${i}" = "smtp_server.regexp" ] || [ "${i}" = "sqlgrey.conf" ] || ${TOUCH} ${PREFIX}/${ETCDIR}/${i}.local
	@[ -f ${PREFIX}/${ETCDIR}/${i} ] || ${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/${ETCDIR}/${i}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
