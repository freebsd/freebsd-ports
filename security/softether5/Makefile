# $FreeBSD$

PORTNAME=	softether
DISTVERSION=	5.01.9671
#PORTREVISION=	0
CATEGORIES=	security
PKGNAMESUFFIX=	5

MAINTAINER=	meta@FreeBSD.org
COMMENT=	SoftEther VPN 5 (Developer Edition)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		cmake:noninja compiler:c11 dos2unix iconv:wchar_t \
		localbase:ldflags ncurses readline ssl
USE_RC_SUBR=	softether_bridge softether_client softether_server
USE_LDCONFIG=	yes
USE_GITHUB=	yes

DOS2UNIX_GLOB=	*.h *.c

GH_ACCOUNT=	SoftEtherVPN
GH_PROJECT=	SoftEtherVPN

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

PORTDOCS=	DISCLAIMER.md WARNING.TXT
CONFLICTS_INSTALL=	softether-4.[0-9]* softether-devel-4.[0-9]*

SE_DBDIR?=	/var/db/${PORTNAME}
SE_LOGDIR?=	/var/log/${PORTNAME}
PLIST_SUB=	SE_DBDIR="${SE_DBDIR}" SE_LOGDIR="${SE_LOGDIR}"
SUB_LIST=	SE_DBDIR="${SE_DBDIR}" SE_LOGDIR="${SE_LOGDIR}"
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

# devel/cpu_features not available on these archs, see devel/cpu_features/Makefile
.if (${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == mips || ${ARCH} == mips64)
# skip cpu_features when devel/cpu_features is not available
CFLAGS+=	-DSKIP_CPU_FEATURES
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/cpu_features_macros.h:devel/cpu_features
.endif

pre-configure:
	# not a GNU configure
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure

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

post-install:
	@${MKDIR} ${STAGEDIR}${SE_LOGDIR} ${STAGEDIR}${SE_DBDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${FIND} ${WRKSRC} -name ${doc} -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR} \;
.endfor

.include <bsd.port.post.mk>
