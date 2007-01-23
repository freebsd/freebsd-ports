# New ports collection makefile for:		portscout
# Date created:					2006-05-15
# Whom:						Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	portscout
PORTVERSION=	0.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/	\
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

.if defined(WITH_MYSQL)
WITHOUT_PGSQL=	true
.endif

.if !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.elif defined(WITH_MYSQL)
USE_MYSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER:S/323//}
.endif

pre-everything::
.if defined(WITH_MYSQL)
	@${ECHO_MSG} "+-------------------------------------------------------------+"
	@${ECHO_MSG} "| Warning! portscout has only been tested with PostgreSQL.    |"
	@${ECHO_MSG} "| The author makes no guarantee that anything else will work, |"
	@${ECHO_MSG} "| but always welcomes success/bug reports, and/or patches.    |"
	@${ECHO_MSG} "+-------------------------------------------------------------+"
.endif

post-patch:
.if defined(WITH_MYSQL)
	@${REINPLACE_CMD} 's/DBI:Pg/DBI:mysql/g' ${WRKSRC}/portscout.conf
.endif
	@${REINPLACE_CMD} -e "s#^\(templates .*\)/etc#\1/share#"	\
	                  -e "s#^prefix\( *= *\).*#prefix\1${PREFIX}#"	\
	                  ${WRKSRC}/portscout.conf
	@${REINPLACE_CMD} -e "s#^\(.*PREFIX.*=> *\)'.*'#\1'${PREFIX}'#"	\
	                  ${WRKSRC}/portscout.pl
	@${REINPLACE_CMD} -e "s#portscout\.pl#portscout#"		\
	                  ${WRKSRC}/README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portscout.pl ${PREFIX}/bin/portscout

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or above. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
