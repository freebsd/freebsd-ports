# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=	pandora_agent
CATEGORIES=	net-mgmt

MAINTAINER=	koichiro@rworks.jp
COMMENT=	Pandora FMS agent, Perl version

LICENSE=	${PANDORA_LICENSE}
LICENSE_FILE=	${PANDORA_LICENSE_FILE}

OPTIONS_DEFINE=		DOCS TENTACLE_SERVER
OPTIONS_DEFAULT=	TENTACLE_SERVER
TENTACLE_SERVER_DESC=	Install tentalce_server

USES=		perl5 shebangfix
SHEBANG_FILES=	plugins/pandora_netusage

SUB_FILES=	pkg-message

.include "${.CURDIR}/../pandorafms_server/bsd.pandora.mk"

PORTDOCS+=	README
PANDORA_INSTALLER_ARGS+=	--fakeroot

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTENTACLE_SERVER}
CONFLICTS=	pandora_server-[45]*
PLIST_SUB+=	TENTACLE_SERVER=""
.else
PLIST_SUB+=	TENTACLE_SERVER="@comment "
PANDORA_INSTALLER_ARGS+=	--no-tentacle-server
.endif

PANDORA_INSTALLER_ARGS+=	${STAGEDIR} root ${PERL}

post-patch:
	@${REINPLACE_CMD} -e '\|PREFIX=|s|=[^;]*|=${PREFIX}|' ${WRKSRC}/pandora_agent_installer

post-install:
	@${RM} ${STAGEDIR}${LOGDIR}/pandora_agent.log
	@${RM} ${STAGEDIR}${DATADIR}/collections/.empty
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MV} ${STAGEDIR}${ETCDIR}/pandora_agent.conf ${STAGEDIR}${ETCDIR}/pandora_agent.conf.sample

.include <bsd.port.post.mk>
