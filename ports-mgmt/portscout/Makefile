# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	portscout
PORTVERSION=	0.8.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/	\
		http://www.atarininja.org/~wxs/distfiles/		\
		http://www.inerd.com/software/${PORTNAME}/

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	A tool to scan for new versions of FreeBSD ports

OPTIONS_DEFINE=	SQLITE3 DOCS
SQLITE3_DESC=	Use SQLite backend instead of PostgreSQL

USES=		perl5
NO_BUILD=	yes

PORTDOCS=	UPDATING portscout-portconfig.txt xml-datasrc-example.xml

MAN1=		portscout.1

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI	\
		p5-Proc-Queue>=0:${PORTSDIR}/devel/p5-Proc-Queue	\
		p5-Net>=0:${PORTSDIR}/net/p5-Net			\
		p5-URI>=0:${PORTSDIR}/net/p5-URI			\
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath	\
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite		\
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE=	3
RUN_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
.elif !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

pre-everything::
.if ${PORT_OPTIONS:MSQLITE3}
	@${ECHO_MSG} "+-------------------------------------------------------------+"
	@${ECHO_MSG} "| Warning! although SQLite is supported, portscout will only  |"
	@${ECHO_MSG} "| operate in non-forking mode with this database backend. It  |"
	@${ECHO_MSG} "| is therefore recommended only for use with light workloads. |"
	@${ECHO_MSG} "+-------------------------------------------------------------+"
.endif

post-patch:
.if ${PORT_OPTIONS:MSQLITE3}
	@${REINPLACE_CMD} 's/^\([^#]*DBI:Pg.*\)$$/#\1/g' ${WRKSRC}/portscout.conf
	@${REINPLACE_CMD} 's/^#\(.*DBI:SQLite.*\)$$/\1/g' ${WRKSRC}/portscout.conf
.endif
	@${REINPLACE_CMD} -e "s#^\(templates .*\)/etc#\1/share#"	\
	                  -e "s#^prefix\( *= *\).*#prefix\1${PREFIX}#"	\
	                  ${WRKSRC}/portscout.conf
	@${REINPLACE_CMD} -e "s#^\(.*PREFIX.*=> *\)'.*'#\1'${PREFIX}'#"	\
	                  ${WRKSRC}/Portscout/Const.pm
	@${MV} ${WRKSRC}/docs/*.* ${WRKSRC}

do-install:
	@${MKDIR} ${SITE_PERL}/Portscout
	@${MKDIR} ${SITE_PERL}/Portscout/DataSrc
	@${MKDIR} ${SITE_PERL}/Portscout/SiteHandler
	@${MKDIR} ${SITE_PERL}/Portscout/SQL
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/*.pm ${SITE_PERL}/Portscout/
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/DataSrc/*.pm ${SITE_PERL}/Portscout/DataSrc/
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/SiteHandler/*.pm ${SITE_PERL}/Portscout/SiteHandler/
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/SQL/*.pm ${SITE_PERL}/Portscout/SQL/
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout.pm ${SITE_PERL}/Portscout.pm
	${INSTALL_SCRIPT} ${WRKSRC}/portscout.pl ${PREFIX}/bin/portscout

	${INSTALL_DATA} ${WRKSRC}/portscout.pod ${SITE_PERL}

	pod2man ${WRKSRC}/portscout.pod ${WRKSRC}/portscout.1
	${INSTALL_MAN} ${WRKSRC}/portscout.1 ${MAN1PREFIX}/man/man1/

	@${MKDIR} ${DATADIR}/templates
	cd ${WRKSRC}/templates \
	  && ${INSTALL_DATA} * ${DATADIR}/templates

	@${MKDIR} ${DATADIR}/sql
	cd ${WRKSRC}/sql && ${INSTALL_DATA} *.sql ${DATADIR}/sql

	${INSTALL_DATA} ${WRKSRC}/portscout.conf ${PREFIX}/etc/portscout.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/portscout.conf ]; then \
		${CP} -p ${PREFIX}/etc/portscout.conf.sample ${PREFIX}/etc/portscout.conf; \
	fi
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.	for f in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.	endfor
.endif

test:
	${PERL} ${WRKSRC}/t/00-use.t
	${PERL} ${WRKSRC}/t/01-vercompare.t
.if ${PORT_OPTIONS:MSQLITE3}
	${PERL} ${WRKSRC}/t/10-sqlite.t
#.else
#	${PERL} ${WRKSRC}/10-postgresql.t
.endif

.include <bsd.port.mk>
