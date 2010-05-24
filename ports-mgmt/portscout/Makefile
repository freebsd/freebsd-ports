# New ports collection makefile for:		portscout
# Date created:					2006-05-15
# Whom:						Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	portscout
PORTVERSION=	0.8
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/	\
		http://www.atarininja.org/~wxs/distfiles/		\
		http://www.inerd.com/software/${PORTNAME}/

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	A tool to scan for new versions of FreeBSD ports

OPTIONS=	SQLITE3 "Use SQLite backend instead of PostgreSQL" off

NO_BUILD=	yes
USE_PERL5=	yes

PORTDOCS=	UPDATING portscout-portconfig.txt xml-datasrc-example.xml

MAN1=		portscout.1

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI	\
		${SITE_PERL}/Proc/Queue.pm:${PORTSDIR}/devel/p5-Proc-Queue	\
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net			\
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI			\
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath	\
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite		\
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

.if defined(WITH_SQLITE3)
USE_SQLITE=	3
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
.elif !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

pre-everything::
.if defined(WITH_SQLITE3)
	@${ECHO_MSG} "+-------------------------------------------------------------+"
	@${ECHO_MSG} "| Warning! although SQLite is supported, portscout will only  |"
	@${ECHO_MSG} "| operate in non-forking mode with this database backend. It  |"
	@${ECHO_MSG} "| is therefore recommended only for use with light workloads. |"
	@${ECHO_MSG} "+-------------------------------------------------------------+"
.endif

post-patch:
.if defined(WITH_SQLITE3)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for f in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.	endfor
.endif

test:
	${PERL} ${WRKSRC}/t/00-use.t
	${PERL} ${WRKSRC}/t/01-vercompare.t
.if defined(WITH_SQLITE3)
	${PERL} ${WRKSRC}/t/10-sqlite.t
#.else
#	${PERL} ${WRKSRC}/10-postgresql.t
.endif

.include <bsd.port.mk>
