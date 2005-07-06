# New ports collection makefile for:    sqlgrey
# Date created:				17 Feb 2005
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	sqlgrey
PORTVERSION=	1.4.8
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Greylisting policy server for Postfix using an SQL backend

RUN_DEPENDS=	${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.elif defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.elif defined(WITH_SQLITE)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

USE_PERL5_RUN=	yes
USE_RC_SUBR=	sqlgrey.sh
USE_BZIP2=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

ETCFILES=	clients_fqdn_whitelist clients_ip_whitelist sqlgrey.conf
SGY_USERNAME?=	sqlgrey
SGY_GROUPNAME?=	${SGY_USERNAME}
ETCDIR?=	etc/sqlgrey

SUB_FILES=	pkg-install
MY_SUB_LIST=	ETCDIR=${ETCDIR} ETCFILES="${ETCFILES}" USER=${SGY_USERNAME} GROUP=${SGY_GROUPNAME} PERL=${PERL}
SUB_LIST=	${MY_SUB_LIST}
PLIST_SUB=	TOUCH=${TOUCH} ${MY_SUB_LIST}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}

MAN1=	sqlgrey.1

.if !defined(NOPORTDOCS)
PORTDOCS=	Changelog FAQ HOWTO README TODO db_performance_reports
.endif

pre-everything::
	@${ECHO_MSG} "You can choose which database to depend on by using"
	@${ECHO_MSG} "  WITH_PGSQL, WITH_MYSQL, or WITH_SQLITE"

post-patch:
	@${REINPLACE_CMD} -e 's-#!/usr/bin/perl-#!${PERL}-' -e 's!/etc/sqlgrey!${PREFIX}/${ETCDIR}!g' ${WRKSRC}/sqlgrey

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sqlgrey ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/update_sqlgrey_whitelists ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKDIR}/sqlgrey.sh ${PREFIX}/etc/rc.d
	@cd ${WRKSRC} && perldoc -u sqlgrey | pod2man sqlgrey > ${MANPREFIX}/man/man1/sqlgrey.1
	@${MKDIR} ${PREFIX}/${ETCDIR}
.for i in ${ETCFILES}
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/${ETCDIR}/${i}.dist
	@[ "${i}" = "sqlgrey.conf" ] || ${TOUCH} ${PREFIX}/${ETCDIR}/${i}.local
	@[ -f ${PREFIX}/${ETCDIR}/${i} ] || ${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/${ETCDIR}/${i}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long
.endif

.include <bsd.port.post.mk>
