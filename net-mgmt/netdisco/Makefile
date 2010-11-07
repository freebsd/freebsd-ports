# New ports collection makefile for:	netdisco
# Date created:				2006-04-08
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	netdisco
PORTVERSION=	1.0
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_with_mibs

MAINTAINER=	venture37@geeklan.co.uk
COMMENT=	Web-based network management tool for moderate to large networks

RUN_DEPENDS+=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP				\
		${SITE_PERL}/SNMP/Info.pm:${PORTSDIR}/net-mgmt/p5-SNMP-Info				\
		${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason				\
		${SITE_PERL}/DB_File/Lock.pm:${PORTSDIR}/devel/p5-DB_File-Lock				\
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session			\
		${SITE_PERL}/Net/NBName.pm:${PORTSDIR}/net/p5-Net-NBName				\
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg			\
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test			\
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser		\
		${SITE_PERL}/MasonX/Request/WithApacheSession.pm:${PORTSDIR}/www/p5-MasonX-Request-WithApacheSession

OPTIONS=	GRAPHVIZ "Install GraphViz for network map support"	on

USERS=		netdisco
GROUPS=		netdisco

USE_PERL5=	yes
USE_PGSQL=	yes
USE_APACHE=	1.3+

USE_RC_SUBR=	netdisco

NO_BUILD=	yes

RUNDIR?=	/var/run
DBDIR?=		/var/db

SUB_FILES=	pkg-message
SUB_LIST=	DBDIR=${DBDIR}
PLIST_SUB=	DBDIR=${DBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALTER_FILES=	netdisco netdisco.conf netdisco_apache.conf \
		netdisco_apache_dir.conf netdisco.crontab sql/pg

CONFIG_FILES=	netdisco.conf netdisco.crontab netdisco-topology.txt \
		netdisco_apache.conf netdisco_apache_dir.conf

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.if ${APACHE_VERSION} >= 20
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/${PERL_ARCH}/APR/Request/Apache2.pm:${PORTSDIR}/www/p5-libapreq2 \
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp2
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl	\
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp1
.endif

.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=	${SITE_PERL}/Graph.pm:${PORTSDIR}/math/p5-Graph	\
		${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz
.endif

pre-install:
.	for i in ${ALTER_FILES}
		@(${MV} ${WRKSRC}/${i}.bak ${WRKSRC}/${i} 2>/dev/null || ${TRUE})
.	endfor

	cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's#%%WWWDIR%%#${WWWDIR}#g'		\
			-e 's#%%PREFIX%%#${PREFIX}#g'		\
			-e 's#%%DATADIR%%#${DATADIR}#g'		\
			-e 's#%%RUNDIR%%#${RUNDIR}#g'		\
			-e 's#%%DBDIR%%#${DBDIR}#g'		\
			-e 's#%%ETCDIR%%#${ETCDIR}#g'		\
			-e 's#%%SITE_PERL%%#${SITE_PERL}#g'	\
			-e 's#%%LOCALBASE%%#${LOCALBASE}#g'	\
			-e 's#%%APACHEMODDIR%%#${APACHEMODDIR}#g'\
			${ALTER_FILES}

do-install:
.	for i in netdisco bin/parse_mac bin/port_control bin/parse_kismet_ap
		cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${PREFIX}/bin
.	endfor

	${MKDIR} ${WWWDIR}
	cd ${WRKSRC}/html && ${INSTALL_DATA} autohandler *.* ${WWWDIR}

	${MKDIR} ${WWWDIR}/doc
	cd ${WRKSRC}/html/doc && ${INSTALL_DATA} *.* ${WWWDIR}/doc

	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

	${MKDIR} ${WWWDIR}/mason

	${INSTALL_DATA} ${WRKSRC}/netdisco.pm ${SITE_PERL}

	${MKDIR} ${ETCDIR}

.	for i in ${CONFIG_FILES}
		cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${ETCDIR}/${i}.sample
		@(if [ ! -f ${ETCDIR}/${i} ]; then	\
			${CP} ${ETCDIR}/${i}.sample	\
			      ${ETCDIR}/${i};		\
		fi)
.	endfor

	${MKDIR} ${DATADIR}/sql

	cd ${WRKSRC}/sql && \
	   ${INSTALL_DATA} *.sql pg ${DATADIR}/sql

	${MKDIR} ${DATADIR}/mibs

	cd ${WRKSRC} && ${FIND} mibs \
	   | ${CPIO} -pu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

	${MKDIR} ${DBDIR}/${PORTNAME}

	${CHOWN} -R ${USERS}:${GROUPS} ${ETCDIR}
	${CHMOD} -R 660 ${ETCDIR}/*
	${CHOWN} -R ${USERS}:${GROUPS} ${DBDIR}/netdisco

.	if !defined(PACKAGE_BUILDING)
		@(if [ -f ${LOCALBASE}/${APACHEETCDIR}/httpd.conf ] ; then							\
			${ECHO_MSG} "===> Updating ${LOCALBASE}/${APACHEETCDIR}/httpd.conf...";					\
			${ECHO_CMD} "# Netdisco include files" >> ${LOCALBASE}/${APACHEETCDIR}/httpd.conf;			\
			${ECHO_CMD} "Include ${ETCDIR}/netdisco_apache.conf" >> ${LOCALBASE}/${APACHEETCDIR}/httpd.conf;	\
			${ECHO_CMD} "Include ${ETCDIR}/netdisco_apache_dir.conf" >> ${LOCALBASE}/${APACHEETCDIR}/httpd.conf;	\
		fi)
.	endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
