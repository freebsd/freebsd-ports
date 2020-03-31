# $FreeBSD$

PORTNAME=	softether
DISTVERSION=	4.34-9744-beta
CATEGORIES=	security net-vpn
MASTER_SITES=	https://www.softether-download.com/files/softether/v${DISTVERSION}-2020.03.20-tree/Source_Code/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-src-v${DISTVERSION}

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Softether VPN 4 (stable beta version)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Upstream only supports amd64 and i386: https://www.softether.org/3-spec
#IGNORE=		no beta version available right now, use security/softether instead

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
SE_PIDDIR?=	/var/run/${PORTNAME}
PLIST_SUB=	SE_DBDIR="${SE_DBDIR}" SE_LOGDIR="${SE_LOGDIR}" SE_PIDDIR="${SE_PIDDIR}"
SUB_LIST=	SE_DBDIR="${SE_DBDIR}" SE_LOGDIR="${SE_LOGDIR}" SE_PIDDIR="${SE_PIDDIR}"
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
		-e "s|%%SE_DBDIR%%|${SE_DBDIR}|g" \
		-e "s|%%SE_LOGDIR%%|${SE_LOGDIR}|g" \
		-e "s|%%SE_PIDDIR%%|${SE_PIDDIR}|g" \
		${WRKSRC}/src/Mayaqua/FileIO.c

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
	@${MKDIR} \
		${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${SE_DBDIR} \
		${STAGEDIR}${SE_LOGDIR} \
		${STAGEDIR}${SE_PIDDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
