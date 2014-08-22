# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=	pandora_server
PORTREVISION=	1

CATEGORIES=	net-mgmt

MAINTAINER=	koichiro@rworks.jp
COMMENT=	Pandora FMS server

LICENSE=	${PANDORA_LICENSE}
LICENSE_FILE=	${PANDORA_LICENSE_FILE}

PANDORA_DEPS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-NetAddr-IP>=0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		net-snmp>=0:${PORTSDIR}/net-mgmt/net-snmp \
		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6 \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON

BUILD_DEPENDS=	${PANDORA_DEPS}

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-DBD-mysql>=4:${PORTSDIR}/databases/p5-DBD-mysql \
		${LOCALBASE}/bin/wmic:${PORTSDIR}/net-mgmt/wmi-client \
		${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		${PANDORA_DEPS}

OPTIONS_DEFINE=	DOCS TENTACLE XPROBE PGSQL ORACLE EXTRAS
OPTIONS_DEFAULT=	DOCS TENTACLE XPROBE EXTRAS
DOCS_DESC=	Install AUTHORS, ChangeLog and README
TENTACLE_DESC=	Install tentacle_server
XPROBE_DESC=	Install xprobe
PGSQL_DESC=	Use PostgreSQL backend (experimental)
ORACLE_DESC=	Use Oracle backend (experimental)
EXTRAS_DESC=	Extra dependencies for util scripts

USES=		perl5
USE_PERL5+=	fixpacklist
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
RUN_DEPENDS+=	${LOCALBASE}/bin/xprobe2:${PORTSDIR}/net/xprobe
.endif
.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif
.if ${PORT_OPTIONS:MORACLE}
RUN_DEPENDS+=	p5-DBD-Oracle>=0:${PORTSDIR}/databases/p5-DBD-Oracle
.endif
.if ${PORT_OPTIONS:MEXTRAS}
# plugin/bgp_pluin.pl
RUN_DEPENDS+=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP
# plugin/multicast.pl
RUN_DEPENDS+=	p5-IO-Socket-Multicast>=0:${PORTSDIR}/net/p5-IO-Socket-Multicast
# plugin/openvpn_pandoraplugin.pl
RUN_DEPENDS+=	p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet
# plugin/integria_plugin/integria_plugin.sh, plugin/webcheck_plugin.sh,
# plugin/babel_plugin/babel_plugin.sh, plugin/create_integria_incident.sh
RUN_DEPENDS+=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget
# plugin/ipmi-plugin.pl, recon_scripts/ipmi-recon.pl
RUN_DEPENDS+=	${LOCALBASE}/sbin/ipmi-sensors:${PORTSDIR}/sysutils/freeipmi
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
	@${RM} -f ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH}/perllocal.pod
	@${FIND} ${STAGEDIR}${DATADIR} -type l -name PandoraFMS -delete
.for x in pandora_server tentacle_server
	@cd ${STAGEDIR}${PREFIX}/etc/rc.d && test -f ${x} \
		&& ${REINPLACE_CMD} -i "" -e 's|/usr/local|${PREFIX}|g' ${x}
.endfor
	@${MV} ${STAGEDIR}${ETCDIR}/pandora_server.conf ${STAGEDIR}${ETCDIR}/pandora_server.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
