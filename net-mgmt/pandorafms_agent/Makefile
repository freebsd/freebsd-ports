# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=	pandora_agent
PORTVERSION=	${PANDORA_VERSION}
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	koichiro@rworks.jp
COMMENT=	Pandora FMS agent, Perl version

LICENSE=	${PANDORA_LICENSE}
LICENSE_FILE=	${PANDORA_LICENSE_FILE}

OPTIONS_DEFINE=	TENTACLE_SERVER
OPTIONS_DEFAULT=	TENTACLE_SERVER
TENTACLE_SERVER_DESC=	Install tentalce_server

USES=		perl5
SUB_LIST+=	PERL="${PERL}"

MAN1=		pandora_agent.1	tentacle_client.1
MANCOMPRESSED=	yes

SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

.include "${.CURDIR}/../pandorafms_server/bsd.pandora.mk"

PORTDOCS+=	README

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTENTACLE_SERVER}
CONFLICTS=	pandora_server-4*
PLIST_SUB+=	TENTACLE_SERVER=""
.else
PLIST_SUB+=	TENTACLE_SERVER="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MTENTACLE_SERVER}
	@${REINPLACE_CMD} \
		-e '/TENTACLE_SERVER/s/^/#/' \
		${WRKSRC}/pandora_agent_installer
.endif
.if defined(NO_INSTALL_MANPAGES)
	@${REINPLACE_CMD} \
		-e '/PANDORA_MAN/s/^/#/' \
		${WRKSRC}/pandora_agent_installer
.endif
	@${REINPLACE_CMD} -E \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%DATADIR%%|${DATADIR}|g' \
		-e 's|%%MAN1PREFIX%%|${MAN1PREFIX}|g' \
		-e 's|%%PANDORA_ETCDIR%%|${PANDORA_ETCDIR}|g' \
		-e 's|%%PANDORA_HOMEDIR%%|${PANDORA_HOMEDIR}|g' \
		${WRKSRC}/pandora_agent_installer
	@${REINPLACE_CMD} -i "" \
		-e 's,/bin/bash,/bin/sh,' \
		-e 's,md5sum,md5 -r,' \
		${WRKSRC}/plugins/files_indir
	@${REINPLACE_CMD} -i "" \
		-e 's,/usr/bin/perl,${PERL},g' \
		`${GREP} -lr /usr/bin/perl ${WRKSRC} | ${GREP} -v pandora_agent_installer`
	@${REINPLACE_CMD} -i "" \
		-e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/plugins/pandora_update
	@${REINPLACE_CMD} \
		-e 's,`ifconfig ,`/sbin/ifconfig ,g' \
		-e 's,tentacle_client ,${PREFIX}/bin/tentacle_client ,g' \
		${WRKSRC}/pandora_agent

do-install:
	@cd ${WRKSRC} && ${SH} pandora_agent_installer --force-install

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for x in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${x} ${DOCSDIR}
.endfor
.endif
	@if [ ! -e ${ETCDIR}/pandora_agent.conf ]; then \
		cd ${ETCDIR} && ${CP} -p pandora_agent.conf.sample pandora_agent.conf; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
