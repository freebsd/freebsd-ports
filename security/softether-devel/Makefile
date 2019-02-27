# $FreeBSD$

PORTNAME=	softether
DISTVERSION=	4.28-9669-beta
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.softether-download.com/files/softether/v${DISTVERSION}-2018.09.11-tree/Source_Code/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-src-v${DISTVERSION}

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Softether VPN solution (development version)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Upstream only supports amd64 and i386: https://www.softether.org/3-spec

USES=		dos2unix gmake iconv:wchar_t localbase:ldflags ncurses \
		readline ssl
USE_RC_SUBR=	softether_bridge softether_client softether_server

DOS2UNIX_FILES=	ChangeLog LICENSE README *.TXT \
		src/Cedar/*.* src/Mayaqua/*.*

OPTIONS_DEFINE=	DOCS UNLOCK

# Use of some functions in Japan and China is restricted.
# This option Unlocks regional lockout following functions:
#  - RADIUS / NT Domain user authentication function
#  - RSA certificate user authentication function
#  - Deep-inspect packet logging function
#  - Source IP address control list function
#  - syslog transfer function
UNLOCK_DESC=	Unlock regional lockout (JP and CN)
UNLOCK_EXTRA_PATCHES=	${FILESDIR}/extra-patch-unrestrict-enterprise-functions

CONFLICTS_INSTALL=	softether-4.* softether5
PORTDOCS=	AUTHORS.TXT ChangeLog LICENSE README THIRD_PARTY.TXT WARNING.TXT

SE_DBDIR?=	/var/db/${PORTNAME}
SE_LOGDIR?=	/var/log/${PORTNAME}
PLIST_SUB=	SE_DBDIR="${SE_DBDIR}" SE_LOGDIR="${SE_LOGDIR}"
SUB_LIST=	SE_DBDIR="${SE_DBDIR}" SE_LOGDIR="${SE_LOGDIR}"
SUB_FILES=	pkg-message vpncmd

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# a pity the source directory has such a naming scheme, but well
WRKSRC=		${WRKDIR}/v${DISTVERSION:S/-beta$//}

ALL_TARGET=	build

.include <bsd.port.options.mk>

post-patch:
	# SoftEther scatters logs, config files and PID files in PREFIX/libexec
	# directory. To write them in the right place, replace it.
	${REINPLACE_CMD} \
		-e "s|@vpn_server_template|${SE_DBDIR}/vpn_server_template|" \
		-e "s|@vpn_server|${SE_DBDIR}/vpn_server|" \
		-e "s|@vpn_bridge|${SE_DBDIR}/vpn_bridge|" \
		-e "s|@vpn_gate_svc|${SE_DBDIR}/vpn_gate_svc|" \
		-e "s|@vpn_gate_relay|${SE_DBDIR}/vpn_gate_relay|" \
		${WRKSRC}/src/Cedar/Server.c

	${REINPLACE_CMD} \
		-e "s|@adminip|${SE_DBDIR}/adminip|" \
		-e "s|@etherlogger|${SE_DBDIR}/etherlogger|" \
		-e "s|@vpn_client|${SE_DBDIR}/vpn_client|" \
		-e "s|@vpn_router|${SE_DBDIR}/vpn_router|" \
		-e "s|@custom|${SE_DBDIR}/custom|" \
		-e "s|@backup|${SE_DBDIR}/backup|" \
		-e "s|@save_binary|${SE_DBDIR}/save_binary|" \
		-e "s|@lang|${SE_DBDIR}/lang|" \
		-e "s|@azureserver|${SE_DBDIR}/azureserver|" \
		-e "s|@server_log|${SE_LOGDIR}/server|" \
		-e "s|@security_log|${SE_LOGDIR}/security|" \
		-e "s|@packet_log|${SE_LOGDIR}/packet|" \
		-e "s|@secure_nat_log|${SE_LOGDIR}/secure_nat|" \
		-e "s|@client_log|${SE_LOGDIR}/client|" \
		-e "s|@tiny_log|${SE_LOGDIR}/tiny|" \
		-e "s|@carrier_log|${SE_LOGDIR}/carrier|" \
		-e "s|@etherlogger_log|${SE_LOGDIR}/etherlogger|" \
		${WRKSRC}/src/Cedar/Cedar.h \
		${WRKSRC}/src/Cedar/Client.h \
		${WRKSRC}/src/Cedar/Nat.h \
		${WRKSRC}/src/Cedar/Server.c \
		${WRKSRC}/src/Mayaqua/Cfg.c \
		${WRKSRC}/src/Mayaqua/Cfg.h \
		${WRKSRC}/src/Mayaqua/Table.h

	${REINPLACE_CMD} \
		-e "s|abort_error_log\.txt|${SE_LOGDIR}/abort_error_log.txt|" \
		${WRKSRC}/src/Mayaqua/Kernel.c

	${REINPLACE_CMD} \
		-e "s|%%SE_DBDIR%%|${SE_DBDIR}|g" \
		${WRKSRC}/src/Cedar/Protocol.c \
		${WRKSRC}/src/Mayaqua/Unix.c \
		${WRKSRC}/src/Mayaqua/Network.c

	# skip configure at all and copy the corresponding Makefile in place
.if ${ARCH} != "amd64"
	@${CP} ${WRKSRC}/src/makefiles/freebsd_32bit.mak ${WRKSRC}/Makefile
.else
	@${CP} ${WRKSRC}/src/makefiles/freebsd_64bit.mak ${WRKSRC}/Makefile
.endif
	# pull in user specific CFLAGS and LDFLAGS
	@${REINPLACE_CMD} -e "s|OPTIONS_COMPILE_RELEASE=|OPTIONS_COMPILE_RELEASE=${CFLAGS} |g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|OPTIONS_LINK_RELEASE=|OPTIONS_LINK_RELEASE=${LDFLAGS} |g" ${WRKSRC}/Makefile

# manually install to ${PREFIX}/libexec/softether, then the final install will copy scripts
# into ${PREFIX}/sbin
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/softether
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vpnbridge/vpnbridge ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/vpnbridge
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vpnclient/vpnclient ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/vpnclient
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vpncmd/vpncmd ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/vpncmd
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vpnserver/vpnserver ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/vpnserver
	${INSTALL_DATA} ${WRKSRC}/bin/vpnserver/hamcore.se2 ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/hamcore.se2
	${INSTALL_SCRIPT} ${WRKDIR}/vpncmd ${STAGEDIR}/${PREFIX}/sbin/vpncmd
.for i in vpnbridge vpnclient vpncmd vpnserver
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/${i}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${SE_DBDIR}
	@${MKDIR} ${STAGEDIR}${SE_LOGDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
