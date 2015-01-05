# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	netdisco
PORTVERSION=	1.3.3
PORTREVISION=	3
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Web-based network management tool for moderate to large networks

LICENSE=	BSD3CLAUSE

RUN_DEPENDS+=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
		p5-SNMP-Info>=3.01:${PORTSDIR}/net-mgmt/p5-SNMP-Info \
		p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
		p5-DB_File-Lock>=0:${PORTSDIR}/devel/p5-DB_File-Lock \
		p5-Apache-Session>=0:${PORTSDIR}/www/p5-Apache-Session \
		p5-Net-NBName>=0:${PORTSDIR}/net/p5-Net-NBName \
		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager

OPTIONS_DEFINE=	DOCS GRAPHVIZ MIBS WEBUI
OPTIONS_DEFAULT=DOCS GRAPHVIZ MIBS WEBUI
OPTIONS_SUB=	WEBUI
MIBS_DESC=	Depend on net-mgmt/netdisco-mibs
GRAPHVIZ_DESC=	Install GraphViz for network map support
WEBUI_DESC=	With web interface (mod_perl2+apache22)

GRAPHVIZ_RUN_DEPENDS+=	p5-Graph>=0:${PORTSDIR}/math/p5-Graph	\
			p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
WEBUI_RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
			p5-Apache-DBI>=0:${PORTSDIR}/www/p5-Apache-DBI	\
			p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2 \
			p5-MasonX-Request-WithApacheSession>=0:${PORTSDIR}/www/p5-MasonX-Request-WithApacheSession
WEBUI_USE=		APACHE_RUN=22+

USES=		perl5 pgsql shebangfix
SHEBANG_FILES=	bin/parse_kismet_ap netdisco
USE_PERL5=	run build

USE_RC_SUBR=	netdisco

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NETDISCO_USER=	netdisco
NETDISCO_GROUP=	netdisco
NETDISCO_RUNDIR=/var/run
NETDISCO_DBDIR=	/var/db/netdisco

USERS=		${NETDISCO_USER}
GROUPS=		${NETDISCO_GROUP}

SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		NETDISCO_USER=${NETDISCO_USER} \
		NETDISCO_GROUP=${NETDISCO_GROUP}
SUB_LIST=	NETDISCO_USER=${NETDISCO_USER} \
		NETDISCO_GROUP=${NETDISCO_GROUP} \
		NETDISCO_DBDIR=${NETDISCO_DBDIR}

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

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's#%%WWWDIR%%#${WWWDIR}#g'		\
		-e 's#%%PREFIX%%#${PREFIX}#g'		\
		-e 's#%%DATADIR%%#${DATADIR}#g'		\
		-e 's#%%DOCSDIR%%#${DOCSDIR}#g'		\
		-e 's#%%NETDISCO_RUNDIR%%#${NETDISCO_RUNDIR}#g'	\
		-e 's#%%NETDISCO_USER%%#${USERS}#g'		\
		-e 's#%%NETDISCO_GROUP%%#${GROUPS}#g'		\
		-e 's#%%NETDISCO_DBDIR%%#${NETDISCO_DBDIR}#g'	\
		-e 's#%%ETCDIR%%#${ETCDIR}#g'		\
		-e 's#%%SITE_PERL%%#${PREFIX}/${SITE_PERL_REL}#g'	\
		-e 's#%%APACHEMODDIR%%#${APACHEMODDIR}#g'	\
		-e 's#%%APACHEETCDIR%%#${APACHEETCDIR}#g'	\
		-e 's#%%MIBINCLUDES%%#${MIBINCLUDES}#g'	\
		${ALTER_FILES})

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL} \
		${STAGEDIR}${DATADIR}/sql \
		${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} netdisco bin/parse_mac \
		bin/port_control bin/parse_kismet_ap ${STAGEDIR}${PREFIX}/bin)
	${INSTALL_DATA} ${WRKSRC}/netdisco.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
.	if ${PORT_OPTIONS:MWEBUI}
		@${MKDIR} ${STAGEDIR}${WWWDIR}/mason
		(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
		(cd ${STAGEDIR}${WWWDIR} && ${RM} -r doc/autohandler svg)
.	endif
.	for i in ${CONFIG_FILES}
	    ${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.	endfor
	(cd ${WRKSRC}/sql && \
		${INSTALL_DATA} *.sql pg ${STAGEDIR}${DATADIR}/sql)
	${INSTALL_DATA} ${WRKSRC}/Makefile ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_MAN} ${DOCFILES} ${STAGEDIR}${DOCSDIR})

#	This violates STAGEDIR, comment out the entire block
#.	if !defined(PACKAGE_BUILDING)
#		@(if [ -d ${PREFIX}/${APACHEETCDIR}/Includes ] ; then \
#			${ECHO_MSG} "===> Adding config in ${PREFIX}/${APACHEETCDIR}/Includes..."; \
#			test -L ${PREFIX}/${APACHEETCDIR}/Includes/netdisco_apache.conf || \
#				${LN} -s ${ETCDIR}/netdisco_apache.conf ${PREFIX}/${APACHEETCDIR}/Includes/netdisco_apache.conf; \
#			test -L ${PREFIX}/${APACHEETCDIR}/Includes/netdisco_apache_dir.conf || \
#				${LN} -s ${ETCDIR}/netdisco_apache_dir.conf ${PREFIX}/${APACHEETCDIR}/Includes/netdisco_apache_dir.conf; \
#		fi)
#.	endif

.include <bsd.port.mk>
