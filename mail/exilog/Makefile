PORTNAME=	exilog
PORTVERSION=	0.5
PORTREVISION=	12
CATEGORIES=	mail
MASTER_SITES=	http://duncanthrax.net/exilog/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to centralize and visualize Exim logs with a web front end
WWW=		https://duncanthrax.net/exilog/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask \
		p5-CGI>0:www/p5-CGI

USES=		perl5 shebangfix
SHEBANG_GLOB=	*.pl

.ifndef WITHOUT_WWWDIR
EXILOGDIR?=	${PREFIX}/www/exilog
.else
EXILOGDIR?=	${PREFIX}/exilog
.endif

OPTIONS_DEFINE=			DOCS AGENT
OPTIONS_MULTI=			SQLBACKEND
OPTIONS_MULTI_SQLBACKEND=	MYSQL PGSQL
OPTIONS_DEFAULT=		AGENT DOCS MYSQL
OPTIONS_SUB=			YES
AGENT_DESC=			Include exilog agent

MYSQL_RUN_DEPENDS=	${DBD_MYSQL}
MYSQL_USES=		mysql

PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
PGSQL_USES=		pgsql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAGENT}
USE_RC_SUBR=	${PORTNAME}
.endif

NO_BUILD=	yes
NO_ARCH=	yes

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
	@${REINPLACE_CMD} -e "s,\(use exilog_config\),use lib \'${EXILOGDIR}\'; \1," ${WRKSRC}/exilog_cgi.pl

do-install:
	${MKDIR} ${STAGEDIR}${EXILOGDIR} ${STAGEDIR}${EXILOGDIR}/icons
	${CP} ${WRKSRC}/*.pm ${WRKSRC}/*.css ${WRKSRC}/*.js ${STAGEDIR}${EXILOGDIR}
	${CP} ${WRKSRC}/icons/* ${STAGEDIR}${EXILOGDIR}/icons
.if ${PORT_OPTIONS:MAGENT}
	${INSTALL_SCRIPT} ${WRKSRC}/exilog_agent.pl ${STAGEDIR}${PREFIX}/sbin
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/exilog_cleanup.pl ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/exilog_cgi.pl ${STAGEDIR}${EXILOGDIR}
	${CP} ${WRKSRC}/exilog.conf-example ${STAGEDIR}${PREFIX}/etc/exilog.conf-dist
	${CP} ${FILESDIR}/htaccess ${STAGEDIR}${EXILOGDIR}/.htaccess
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
