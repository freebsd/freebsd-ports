# New ports collection makefile for:		portscout
# Date created:					2006-05-15
# Whom:						Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	portscout
PORTVERSION=	0.7.3
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/	\
		http://www.atarininja.org/~wxs/distfiles/		\
		http://www.inerd.com/software/${PORTNAME}/

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	A tool to scan for new versions of FreeBSD ports

NO_BUILD=	yes
USE_PERL5=	yes

PORTDOCS=	README

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI	\
		${SITE_PERL}/Proc/Queue.pm:${PORTSDIR}/devel/p5-Proc-Queue	\
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net			\
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite		\
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

.if defined(WITH_MYSQL) || defined(WITH_SQLITE3)
WITHOUT_PGSQL=	true
BROKEN=		MySQL/SQLite3 is not supported yet; portscout will not work with it
.endif

.if !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.elif defined(WITH_MYSQL)
USE_MYSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER:S/323//}
EXTRA_PATCHES+=	${WRKSRC}/patches/mysql.diff
.elif defined(WITH_SQLITE3)
USE_SQLITE=	3
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
EXTRA_PATCHES+=	${WRKSRC}/patches/sqlite3.diff
.endif

pre-everything::
.if defined(WITH_MYSQL) || defined(WITH_SQLITE3)
	@${ECHO_MSG} "+-------------------------------------------------------------+"
	@${ECHO_MSG} "| Warning! portscout has only been tested with PostgreSQL.    |"
	@${ECHO_MSG} "| The author makes no guarantee that anything else will work, |"
	@${ECHO_MSG} "| but always welcomes success/bug reports, and/or patches.    |"
	@${ECHO_MSG} "+-------------------------------------------------------------+"
.endif

post-patch:
.if defined(WITH_MYSQL)
	@${REINPLACE_CMD} 's/DBI:Pg/DBI:mysql/g' ${WRKSRC}/portscout.conf
.elif defined(WITH_SQLITE3)
	@${REINPLACE_CMD} 's/DBI:Pg/DBI:SQLite/g' ${WRKSRC}/portscout.conf
.endif
	@${REINPLACE_CMD} -e "s#^\(templates .*\)/etc#\1/share#"	\
	                  -e "s#^prefix\( *= *\).*#prefix\1${PREFIX}#"	\
	                  ${WRKSRC}/portscout.conf
	@${REINPLACE_CMD} -e "s#^\(.*PREFIX.*=> *\)'.*'#\1'${PREFIX}'#"	\
	                  ${WRKSRC}/portscout.pl
	@${REINPLACE_CMD} -e "s#portscout\.pl#portscout#"		\
	                  ${WRKSRC}/README

do-install:
	@${MKDIR} ${SITE_PERL}/Portscout
	${INSTALL_SCRIPT} ${WRKSRC}/portscout.pl ${PREFIX}/bin/portscout
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout.pm ${SITE_PERL}/Portscout.pm
	${INSTALL_SCRIPT} ${WRKSRC}/Portscout/Template.pm ${SITE_PERL}/Portscout

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
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
