# Created by: mat
# $FreeBSD$

PORTNAME=	sqlgrey
PORTVERSION=	1.8.0
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.8%20%28stable%29

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Greylisting policy server for Postfix using an SQL backend

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Net-Server>=0:net/p5-Net-Server \
		p5-IO-Multiplex>=0:devel/p5-IO-Multiplex \
		p5-Pod-Parser>=0:textproc/p5-Pod-Parser \
		${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/gmd5sum:sysutils/coreutils

USES=		perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/sqlgrey-logstats.pl ${WRKSRC}/update_sqlgrey_config ${WRKSRC}/sqlgrey
USE_PERL5=	run
USE_RC_SUBR=	sqlgrey
NO_BUILD=	yes
NO_ARCH=	yes

ETCFILES=	clients_fqdn_whitelist clients_ip_whitelist dyn_fqdn.regexp smtp_server.regexp sqlgrey.conf
USERS=		sqlgrey
GROUPS=		${USERS}

SUB_LIST=	PERL=${PERL} USERS=${USERS} GROUPS=${GROUPS}
PLIST_SUB=	TOUCH=${TOUCH}

PORTDOCS=	Changelog FAQ HOWTO README TODO

OPTIONS_DEFINE=	PGSQL MYSQL SQLITE STATS DOCS
OPTIONS_DEFAULT=PGSQL
STATS_DESC=	Depend on Date::Calc for logstats.pl script

PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
SQLITE_RUN_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite
STATS_RUN_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc

post-patch:
	@${REINPLACE_CMD} -e 's!/etc/sqlgrey!${ETCDIR}!g' ${WRKSRC}/sqlgrey

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sqlgrey-logstats.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sqlgrey ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/update_sqlgrey_config ${STAGEDIR}${PREFIX}/sbin
	cd ${WRKSRC} && perldoc -u sqlgrey | pod2man sqlgrey > ${STAGEDIR}${MANPREFIX}/man/man1/sqlgrey.1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
