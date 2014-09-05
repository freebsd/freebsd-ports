# Created by: mat
# $FreeBSD$

PORTNAME=	sqlgrey
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.8%20%28stable%29

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Greylisting policy server for Postfix using an SQL backend

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-IO-Multiplex>=0:${PORTSDIR}/devel/p5-IO-Multiplex \
		p5-Pod-Parser>=0:${PORTSDIR}/textproc/p5-Pod-Parser

USES=		perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/sqlgrey-logstats.pl ${WRKSRC}/update_sqlgrey_config ${WRKSRC}/sqlgrey
USE_PERL5=	run
USE_RC_SUBR=	sqlgrey
NO_BUILD=	yes

ETCFILES=	clients_fqdn_whitelist clients_ip_whitelist dyn_fqdn.regexp smtp_server.regexp sqlgrey.conf
USERS=		sqlgrey
GROUPS=		${USERS}
ETCDIR?=	etc/sqlgrey

SUB_LIST+=	PERL=${PERL} USERS=${USERS} GROUPS=${GROUPS}
PLIST_SUB=	TOUCH=${TOUCH}

OPTIONS_DEFINE=	PGSQL MYSQL SQLITE STATS DOCS
OPTIONS_DEFAULT=PGSQL
STATS_DESC=	Depend on Date::Calc for logstats.pl script

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	Changelog FAQ HOWTO README TODO
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
.endif

.if ${PORT_OPTIONS:MSTATS}
RUN_DEPENDS+=	p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's-#!/usr/bin/perl-#!${PERL}-' -e 's!/etc/sqlgrey!${PREFIX}/${ETCDIR}!g' ${WRKSRC}/sqlgrey

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sqlgrey-logstats.pl ${STAGEDIR}/${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/sqlgrey ${STAGEDIR}/${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/update_sqlgrey_config ${STAGEDIR}/${PREFIX}/sbin
	@cd ${WRKSRC} && perldoc -u sqlgrey | pod2man sqlgrey > ${STAGEDIR}/${MANPREFIX}/man/man1/sqlgrey.1
	@${MKDIR} ${STAGEDIR}/${PREFIX}/${ETCDIR}
.for i in ${ETCFILES}
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${STAGEDIR}/${PREFIX}/${ETCDIR}/${i}.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}/${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${STAGEDIR}/${DOCSDIR}."
.endif

.include <bsd.port.mk>
