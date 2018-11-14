# $FreeBSD$

PORTNAME=	softether
DISTVERSION=	4.28-9669-beta
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
SUB_FILES=	vpncmd

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

CONFLICTS_INSTALL=	softether
PORTDOCS=	AUTHORS.TXT ChangeLog LICENSE README THIRD_PARTY.TXT WARNING.TXT

LOGDIR?=	/var/log/softether
PLIST_SUB=	LOGDIR="${LOGDIR}"
SUB_LIST=	LOGDIR="${LOGDIR}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# a pity the source directory has such a naming scheme, but well
WRKSRC=		${WRKDIR}/v${DISTVERSION:S/-beta$//}

ALL_TARGET=	build

.include <bsd.port.options.mk>

post-patch:
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
	@${MKDIR} ${STAGEDIR}${LOGDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
