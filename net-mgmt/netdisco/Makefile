# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	netdisco
PORTVERSION=	1.3.3
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Web-based network management tool for moderate to large networks

OPTIONS_DEFINE=	DOCS GRAPHVIZ MIBS WEBUI
OPTIONS_DEFAULT=DOCS GRAPHVIZ MIBS WEBUI
MIBS_DESC=	Depend on net-mgmt/netdisco-mibs
GRAPHVIZ_DESC=	Install GraphViz for network map support
WEBUI_DESC=	With web interface (mod_perl2+apache22)

RUN_DEPENDS+=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-SNMP-Info>=3.01:${PORTSDIR}/net-mgmt/p5-SNMP-Info \
		p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
		p5-DB_File-Lock>=0:${PORTSDIR}/devel/p5-DB_File-Lock \
		p5-Apache-Session>=0:${PORTSDIR}/www/p5-Apache-Session \
		p5-Net-NBName>=0:${PORTSDIR}/net/p5-Net-NBName \
		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager

USES=		perl5 shebangfix
USE_PERL5=	run build fixpacklist
USE_PGSQL=	yes

USE_RC_SUBR=	netdisco

NO_BUILD=	yes

NETDISCO_USER=	netdisco
NETDISCO_GROUP=	netdisco
NETDISCO_RUNDIR=/var/run
NETDISCO_DBDIR=	/var/db/netdisco

SUB_FILES=	pkg-message
#SUB_LIST=	NETDISCO_DBDIR=${NETDISCO_DBDIR} NETDISCO_RUNDIR=${NETDISCO_RUNDIR} NETDISCO_USER=${NETDISCO_USER} NETDISCO_GROUP=${NETDISCO_GROUP}
PLIST_SUB=	NETDISCO_DBDIR=${NETDISCO_DBDIR} NETDISCO_RUNDIR=${NETDISCO_RUNDIR} NETDISCO_USER=${NETDISCO_USER}
SHEBANG_FILES=	bin/parse_kismet_ap netdisco

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALTER_FILES=	netdisco netdisco.conf netdisco_apache.conf \
		netdisco_apache_dir.conf netdisco.crontab sql/pg

CONFIG_FILES=	netdisco.conf netdisco.crontab netdisco-topology.txt \
		netdisco_apache.conf netdisco_apache_dir.conf

DOCFILES=	ChangeLog doc/*.pod INSTALL README* UPGRADE

.include <bsd.port.options.mk>

MIBSDIR=	${PREFIX}/share/netdisco-mibs
.if ${PORT_OPTIONS:MMIBS}
RUN_DEPENDS+=	${MIBSDIR}/mib_index.txt:${PORTSDIR}/net-mgmt/netdisco-mibs
BUILD_DEPENDS+=	${MIBSDIR}/mib_index.txt:${PORTSDIR}/net-mgmt/netdisco-mibs
. include	"${.CURDIR}/../netdisco-mibs/bsd.port.netdisco.mk"
MIBINCLUDES!=${ECHO} \"${MIBDIRS:S/^/${MIBSDIR}\//}\"
MIBINCLUDES:=${MIBINCLUDES:S/ /:/g:S/"//g}
.else
MIBINCLUDES="#please add here mibs dirs list (at least snmp and rfc ones)"
.endif

REINPLACE_EXPR=	-e 's!%%PREFIX%%!${PREFIX}!g' -e 's!%%DATADIR%%!${DATADIR}!g' \
	-e 's!%%DOCSDIR%%!${DOCSDIR}!g' -e 's!%%NETDISCO_RUNDIR%%!${NETDISCO_RUNDIR}!g' \
	-e 's!%%NETDISCO_USER%%!${NETDISCO_USER}!g' -e 's!%%NETDISCO_GROUP%%!${NETDISCO_GROUP}!g' \
	-e 's!%%NETDISCO_DBDIR%%!${NETDISCO_DBDIR}!g' -e 's!%%ETCDIR%%!${ETCDIR}!g' \
	-e 's!%%SITE_PERL%%!${SITE_PERL}!g' -e 's!%%MIBINCLUDES%%!${MIBINCLUDES}!g'

.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	p5-Graph>=0:${PORTSDIR}/math/p5-Graph	\
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
.endif

.if ${PORT_OPTIONS:MWEBUI}
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-Apache-DBI>=0:${PORTSDIR}/www/p5-Apache-DBI	\
		p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2 \
		p5-MasonX-Request-WithApacheSession>=0:${PORTSDIR}/www/p5-MasonX-Request-WithApacheSession
USE_APACHE_RUN=	22
REINPLACE_EXPR+=	-e 's!%%APACHEMODDIR%%!${APACHEMODDIR}!g' -e 's!%%APACHEETCDIR%%!${APACHEETCDIR}!g' \
		-e 's!%%WWWDIR%%!${WWWDIR}!g' 
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} WEBUI=""
.else
PLIST_SUB+=     WWWOWN="@comment " \
		WWWGRP="@comment " \
		WWWDIR="@comment " \
		WEBUI="@comment "
.endif

USERS+=		${NETDISCO_USER}
GROUPS+=		${NETDISCO_GROUP}

pre-install:
.	for i in ${ALTER_FILES}
		@(${MV} ${WRKSRC}/${i}.bak ${WRKSRC}/${i} 2>/dev/null || ${TRUE})
.	endfor

	cd ${WRKSRC} && \
	${REINPLACE_CMD} ${REINPLACE_EXPR} ${ALTER_FILES}

do-install:
.	for i in netdisco bin/parse_mac bin/port_control bin/parse_kismet_ap
		cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${STAGEDIR}${PREFIX}/bin
.	endfor

.	if ${PORT_OPTIONS:MWEBUI}
		${MKDIR} ${STAGEDIR}${WWWDIR}
		cd ${WRKSRC}/html && ${INSTALL_DATA} autohandler *.* ${STAGEDIR}${WWWDIR}

		${MKDIR} ${STAGEDIR}${WWWDIR}/doc
		cd ${WRKSRC}/html/doc && ${INSTALL_DATA} *.* ${STAGEDIR}${WWWDIR}/doc
.	endif

	${MKDIR} -m 755 -p ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

	${INSTALL_DATA} ${WRKSRC}/netdisco.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL} -d -m 750 ${STAGEDIR}${ETCDIR}

	${INSTALL} -d ${STAGEDIR}${DATADIR}/sql

	cd ${WRKSRC}/sql && \
	   ${INSTALL_DATA} *.sql pg ${STAGEDIR}${DATADIR}/sql

	${INSTALL_DATA} ${WRKSRC}/Makefile ${STAGEDIR}${DATADIR}

.	for i in ${CONFIG_FILES}
		${INSTALL} -m 640 ${WRKSRC}/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.	endfor

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_MAN} ${DOCFILES} ${STAGEDIR}${DOCSDIR})
.	if ${PORT_OPTIONS:MWEBUI}
		${ECHO_CMD} "@unexec ${RM} -rf ${WWWDIR}/mason" >> ${TMPPLIST}
		${ECHO_CMD} "@exec ${MKDIR} -m 750 ${WWWDIR}/mason" >> ${TMPPLIST}
		${ECHO_CMD} "@exec ${CHOWN} -R ${WWWOWN} ${WWWDIR}/mason" >> ${TMPPLIST}
		${ECHO_CMD} "@exec ${CHOWN} ${NETDISCO_USER} ${WWWDIR}" >> ${TMPPLIST}
.	endif
	${ECHO_CMD} "@exec ${CHOWN} -R ${NETDISCO_USER}:${NETDISCO_GROUP} ${ETCDIR}"
.	if !defined(PACKAGE_BUILDING)
		@(if [ -d ${PREFIX}/${APACHEETCDIR}/Includes ] ; then							\
			${ECHO_MSG} "===> Adding config in ${PREFIX}/${APACHEETCDIR}/Includes...";					\
			test -L ${PREFIX}/${APACHEETCDIR}/Includes/netdisco_apache.conf || \
				${LN} -s ${ETCDIR}/netdisco_apache.conf ${PREFIX}/${APACHEETCDIR}/Includes/netdisco_apache.conf; \
			test -L ${PREFIX}/${APACHEETCDIR}/Includes/netdisco_apache_dir.conf || \
				${LN} -s ${ETCDIR}/netdisco_apache_dir.conf ${PREFIX}/${APACHEETCDIR}/Includes/netdisco_apache_dir.conf;\
		fi)
.	endif
.	for i in ${CONFIG_FILES}
		cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${ETCDIR}/${i}.sample
		@(if [ ! -f ${STAGEDIR}${ETCDIR}/${i} ]; then	\
			${INSTALL} -m 640 ${STAGEDIR}${ETCDIR}/${i}.sample ${STAGEDIR}${ETCDIR}/${i};	\
		fi)
.	endfor

.include <bsd.port.mk>
