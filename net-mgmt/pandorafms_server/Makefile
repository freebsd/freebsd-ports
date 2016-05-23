# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=	pandora_server
CATEGORIES=	net-mgmt

MAINTAINER=	koichiro@rworks.jp
COMMENT=	Pandora FMS server

LICENSE=	${PANDORA_LICENSE}
LICENSE_FILE=	${PANDORA_LICENSE_FILE}

PANDORA_DEPS=	p5-DBI>=0:databases/p5-DBI \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
		p5-NetAddr-IP>=0:net-mgmt/p5-NetAddr-IP \
		net-snmp>=0:net-mgmt/net-snmp \
		p5-Socket6>=0:net/p5-Socket6 \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-JSON>=0:converters/p5-JSON
BUILD_DEPENDS=	${PANDORA_DEPS}
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-DBD-mysql>=4:databases/p5-DBD-mysql \
		${LOCALBASE}/bin/wmic:net-mgmt/wmi-client \
		${LOCALBASE}/bin/nmap:security/nmap \
		p5-Storable>=0:devel/p5-Storable \
		p5-Encode-Locale>=0:converters/p5-Encode-Locale \
		${PANDORA_DEPS}

OPTIONS_DEFINE=	DOCS TENTACLE XPROBE PGSQL ORACLE EXTRAS
OPTIONS_DEFAULT=	TENTACLE XPROBE EXTRAS
DOCS_DESC=	Install AUTHORS, ChangeLog and README
TENTACLE_DESC=	Install tentacle_server
XPROBE_DESC=	Install xprobe
PGSQL_DESC=	Use PostgreSQL backend (experimental)
ORACLE_DESC=	Use Oracle backend (experimental)
EXTRAS_DESC=	Extra dependencies for util scripts

USES=		perl5 shebangfix
SHEBANG_FILES=	FreeBSD/pandora_server \
		bin/pandora_server \
		util/integrity_check \
		util/pandora_backup.sh \
		util/pandora_count.sh \
		util/pandora_diagnostic.sh \
		util/pandora_remote_agent.sh \
		util/pandora_server \
		util/pandora_watchdog.sh \
		util/plugin/babel_plugin/babel_plugin.sh \
		util/plugin/create_integria_incident.sh \
		util/plugin/dns_plugin.sh \
		util/plugin/integria_plugin/integria_plugin.sh \
		util/plugin/mysql_plugin.sh \
		util/plugin/packet_loss.sh \
		util/plugin/ssh_pandoraplugin.sh \
		util/plugin/udp_nmap_plugin.sh \
		util/plugin/webcheck_plugin.sh \
		util/snmptrap_gen.sh \
		util/tentacle_serverd \
		util/trap_rate.sh
USE_PERL5=	build run
SUB_LIST+=	PERL="${PERL}" DATADIR="${DATADIR}"
SUB_FILES=	pkg-message

.include "${.CURDIR}/bsd.pandora.mk"

PORTDOCS+=	README
PANDORA_INSTALLER_ARGS+=	--destdir ${STAGEDIR}

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MTENTACLE}
PLIST_SUB+=	TENTACLE="@comment "
PANDORA_INSTALLER_ARGS+=--no-tentacle
.else
PLIST_SUB+=	TENTACLE=""
#USE_RC_SUBR+=	tentacle_server
.endif
.if ${PORT_OPTIONS:MXPROBE}
RUN_DEPENDS+=	${LOCALBASE}/bin/xprobe2:net/xprobe
.endif
.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
.endif
.if ${PORT_OPTIONS:MORACLE}
RUN_DEPENDS+=	p5-DBD-Oracle>=0:databases/p5-DBD-Oracle
.endif
.if ${PORT_OPTIONS:MEXTRAS}
# plugin/bgp_pluin.pl
RUN_DEPENDS+=	p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP
# plugin/multicast.pl
RUN_DEPENDS+=	p5-IO-Socket-Multicast>=0:net/p5-IO-Socket-Multicast
# plugin/openvpn_pandoraplugin.pl
RUN_DEPENDS+=	p5-Net-Telnet>=0:net/p5-Net-Telnet
# plugin/integria_plugin/integria_plugin.sh, plugin/webcheck_plugin.sh,
# plugin/babel_plugin/babel_plugin.sh, plugin/create_integria_incident.sh
RUN_DEPENDS+=	${LOCALBASE}/bin/wget:ftp/wget
# plugin/ipmi-plugin.pl, recon_scripts/ipmi-recon.pl
RUN_DEPENDS+=	${LOCALBASE}/sbin/ipmi-sensors:sysutils/freeipmi
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DATADIR%%|${DATADIR}|g' \
		-e 's|%%MAN1PREFIX%%|${MAN1PREFIX}|g' \
		-e 's|%%PANDORA_ETCDIR%%|${PANDORA_ETCDIR}|g' \
		-e 's|%%PANDORA_LOGDIR%%|${PANDORA_LOGDIR}|g' \
		-e 's|%%PANDORA_SPOOLDIR%%|${PANDORA_SPOOLDIR}|g' \
		${WRKSRC}/pandora_server_installer
	@${REINPLACE_CMD} -i "" \
		-e 's,/usr/bin/perl,${PERL},g' \
		`${GREP} -rl /usr/bin/perl ${WRKSRC} | ${GREP} -v pandora_server_installer`

post-install:
	@${FIND} ${STAGEDIR}${DATADIR} -type l -name PandoraFMS -delete
.for x in pandora_server tentacle_server
	@cd ${STAGEDIR}${PREFIX}/etc/rc.d && test -f ${x} \
		&& ${REINPLACE_CMD} -i "" -e 's|/usr/local|${PREFIX}|g' ${x}
.endfor
	@${MV} ${STAGEDIR}${ETCDIR}/pandora_server.conf ${STAGEDIR}${ETCDIR}/pandora_server.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
