# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	portscout
PORTVERSION=	0.8.1
PORTREVISION=	11
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/ \
		http://www.atarininja.org/~wxs/distfiles/ \
		http://www.inerd.com/software/${PORTNAME}/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Tool to scan for new versions of FreeBSD ports

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-CGI>=0:www/p5-CGI \
		p5-Proc-Queue>=0:devel/p5-Proc-Queue \
		p5-URI>=0:net/p5-URI \
		p5-XML-XPath>=0:textproc/p5-XML-XPath \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-libwww>=0:www/p5-libwww \
		p5-JSON>0:converters/p5-JSON

OPTIONS_DEFINE=		DOCS HTTPS
OPTIONS_DEFAULT=	HTTPS PGSQL

OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	SQLITE PGSQL

DATABASE_DESC=	Database Backends
USES=		perl5 shebangfix

NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	${WRKSRC}/portscout.pl

PORTDOCS=	UPDATING portscout-portconfig.txt xml-datasrc-example.xml

HTTPS_RUN_DEPENDS=	p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https

SQLITE_USES=		sqlite
SQLITE_RUN_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

PGSQL_USES=		pgsql
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg

.include <bsd.port.options.mk>

pre-everything::
.if ${PORT_OPTIONS:MSQLITE}
	@${ECHO_MSG} "+-------------------------------------------------------------+"
	@${ECHO_MSG} "| Warning! although SQLite is supported, portscout will only  |"
	@${ECHO_MSG} "| operate in non-forking mode with this database backend. It  |"
	@${ECHO_MSG} "| is therefore recommended only for use with light workloads. |"
	@${ECHO_MSG} "+-------------------------------------------------------------+"
.endif

post-extract:
	@${CP} ${FILESDIR}/files-Portscout-SiteHandler-GitHub.pm ${WRKSRC}/Portscout/SiteHandler/GitHub.pm
	@${CP} ${FILESDIR}/files-Portscout-SiteHandler-PyPI.pm ${WRKSRC}/Portscout/SiteHandler/PyPI.pm

pre-install:
	@${REINPLACE_CMD} -e "s#^\(templates .*\)/etc#\1/share#"	\
	                  -e "s#^prefix\( *= *\).*#prefix\1${PREFIX}#"	\
	                  ${WRKSRC}/portscout.conf
	@${REINPLACE_CMD} -e "s#^\(.*PREFIX.*=> *\)'.*'#\1'${PREFIX}'#"	\
	                  ${WRKSRC}/Portscout/Const.pm
	@${MV} ${WRKSRC}/docs/*.* ${WRKSRC}

pre-install-SQLITE-on:
	@${REINPLACE_CMD} 's/^\([^#]*DBI:Pg.*\)$$/#\1/g' ${WRKSRC}/portscout.conf
	@${REINPLACE_CMD} 's/^#\(.*DBI:SQLite.*\)$$/\1/g' ${WRKSRC}/portscout.conf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout/DataSrc
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout/SiteHandler
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout/SQL
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout/
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/DataSrc/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout/DataSrc/
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/SiteHandler/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout/SiteHandler/
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/SQL/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout/SQL/
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Portscout.pm
	${INSTALL_SCRIPT} ${WRKSRC}/portscout.pl ${STAGEDIR}${PREFIX}/bin/portscout

	${INSTALL_DATA} ${WRKSRC}/portscout.pod ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

	pod2man ${WRKSRC}/portscout.pod ${WRKSRC}/portscout.1
	${INSTALL_MAN} ${WRKSRC}/portscout.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

	@${MKDIR} ${STAGEDIR}${DATADIR}/templates
	cd ${WRKSRC}/templates \
	  && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}/templates

	@${MKDIR} ${STAGEDIR}${DATADIR}/sql
	cd ${WRKSRC}/sql && ${INSTALL_DATA} *.sql ${STAGEDIR}${DATADIR}/sql

	${INSTALL_DATA} ${WRKSRC}/portscout.conf ${STAGEDIR}${PREFIX}/etc/portscout.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for f in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.	endfor

test:
	${PERL} ${WRKSRC}/t/00-use.t
	${PERL} ${WRKSRC}/t/01-vercompare.t
.if ${PORT_OPTIONS:MSQLITE}
	${PERL} ${WRKSRC}/t/10-sqlite.t
#.else
#	${PERL} ${WRKSRC}/10-postgresql.t
.endif

.include <bsd.port.mk>
