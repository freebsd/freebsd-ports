# New ports collection makefile for:	netdisco
# Date created:				2006-04-08
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	netdisco
PORTVERSION=	0.95
PORTREVISION=	2
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_with_mibs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based network management tool for moderate to large networks

RUN_DEPENDS+=	${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP				\
		${SITE_PERL}/SNMP/Info.pm:${PORTSDIR}/net-mgmt/p5-SNMP-Info				\
		${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason				\
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI				\
		${SITE_PERL}/DB_File/Lock.pm:${PORTSDIR}/devel/p5-DB_File-Lock				\
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session			\
		${SITE_PERL}/Net/NBName.pm:${PORTSDIR}/net/p5-Net-NBName				\
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5		\
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg			\
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test			\
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib	\
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser		\
		${SITE_PERL}/MasonX/Request/WithApacheSession.pm:${PORTSDIR}/www/p5-MasonX-Request-WithApacheSession

OPTIONS=	GRAPHVIZ "Install GraphViz for network map support"	on

USE_PERL5=	yes
USE_PGSQL=	yes
USE_APACHE=	1.3+

USE_RC_SUBR=	netdisco

NO_BUILD=	yes

RUNDIR?=	/var/run
DBDIR?=		/var/db
APACHE_CFG=	${APACHE_CFGDIR}/httpd.conf

SUB_FILES=	pkg-message pkg-install
SUB_LIST=	DBDIR=${DBDIR}
PLIST_SUB=	DBDIR=${DBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALTER_FILES=	netdisco netdisco.conf netdisco_apache.conf \
		netdisco_apache_dir.conf netdisco.crontab

CONFIG_FILES=	netdisco.conf netdisco.crontab netdisco-topology.txt \
		netdisco_apache.conf netdisco_apache_dir.conf

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2	\
		${SITE_PERL}/${PERL_ARCH}/APR/Request/Apache2.pm:${PORTSDIR}/www/p5-libapreq2
APACHE_CFGDIR=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl		\
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
APACHE_CFGDIR=	${LOCALBASE}/etc/apache
APACHE2_RE=	\#
.endif

.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=	${SITE_PERL}/Graph.pm:${PORTSDIR}/math/p5-Graph				\
		${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz
.endif

pre-install:
.	for i in ${ALTER_FILES}
		@(${MV} ${WRKSRC}/${i}.bak ${WRKSRC}/${i} 2>/dev/null || ${TRUE})
.	endfor

	cd ${WRKSRC} && \
	   ${REINPLACE_CMD} -e 's#%%WWWDIR%%#${WWWDIR}#g'	\
	                    -e 's#%%PREFIX%%#${PREFIX}#g'		\
	                    -e 's#%%DATADIR%%#${DATADIR}#g'		\
	                    -e 's#%%RUNDIR%%#${RUNDIR}#g'		\
	                    -e 's#%%DBDIR%%#${DBDIR}#g'			\
	                    -e 's/%%APACHE2%%/${APACHE2_RE}/g'		\
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

	${MKDIR} ${PREFIX}/etc/${PORTNAME}

.	for i in ${CONFIG_FILES}
		cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${PREFIX}/etc/${PORTNAME}/${i}.sample
		@(if [ ! -f ${PREFIX}/etc/${PORTNAME}/${i} ]; then	\
			${CP} ${PREFIX}/etc/${PORTNAME}/${i}.sample	\
			      ${PREFIX}/etc/${PORTNAME}/${i};		\
		fi)
.	endfor

	${MKDIR} ${DATADIR}/sql

	cd ${WRKSRC}/sql && \
	   ${INSTALL_DATA} *.sql pg ${DATADIR}/sql

	${MKDIR} ${DATADIR}/mibs

	cd ${WRKSRC} && ${FIND} mibs \
	   | ${CPIO} -pu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

	${MKDIR} ${DBDIR}/${PORTNAME}

.	if !defined(PACKAGE_BUILDING)
		@(if [ -f ${APACHE_CFG} ] ; then \
			${ECHO_MSG} "===> Updating ${APACHE_CFG}...";							\
			${ECHO_CMD} "# Netdisco include files" >> ${APACHE_CFG};					\
			${ECHO_CMD} "Include ${PREFIX}/etc/${PORTNAME}/netdisco_apache.conf" >> ${APACHE_CFG};		\
			${ECHO_CMD} "Include ${PREFIX}/etc/${PORTNAME}/netdisco_apache_dir.conf" >> ${APACHE_CFG};	\
		fi)
.	endif

post-install:
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
