# $FreeBSD$

PORTNAME=	softether
DISTVERSION=	5.01.9672
#PORTREVISION=	0
CATEGORIES=	security net-vpn
PKGNAMESUFFIX=	5
DIST_SUBDIR=	${PORTNAME}

# Some patches are managed in my GitHub fork
PATCH_SITES=	https://github.com/metalefty/${GH_ACCOUNT}/commit/
PATCHFILES=	7a7bed1.patch:-p1 501135e.patch:-p1 13f0ec3.patch:-p1

MAINTAINER=	meta@FreeBSD.org
COMMENT=	SoftEther VPN 5 (Developer Edition)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		cmake:noninja compiler:c11 iconv:wchar_t \
		localbase:ldflags ncurses readline ssl
USE_RC_SUBR=	softether_bridge softether_client softether_server
USE_LDCONFIG=	yes
USE_GITHUB=	yes

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
UNLOCK_PATCHFILES=	940a202.patch:-p1

PORTDOCS=	DISCLAIMER.md WARNING.TXT
CONFLICTS_INSTALL=	softether-4.[0-9]* softether-devel-4.[0-9]*

SE_DBDIR?=	/var/db/${PORTNAME}
SE_LOGDIR?=	/var/log/${PORTNAME}
SE_PIDDIR?=	/var/run/${PORTNAME}
PLIST_SUB=	SE_DBDIR="${SE_DBDIR}" SE_LOGDIR="${SE_LOGDIR}" SE_PIDDIR="${SE_PIDDIR}"
SUB_LIST=	SE_DBDIR="${SE_DBDIR}" SE_LOGDIR="${SE_LOGDIR}" SE_PIDDIR="${SE_PIDDIR}"
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
		-e "s|%%SE_DBDIR%%|${SE_DBDIR}|g" \
		-e "s|%%SE_LOGDIR%%|${SE_LOGDIR}|g" \
		-e "s|%%SE_PIDDIR%%|${SE_PIDDIR}|g" \
		${WRKSRC}/src/Mayaqua/FileIO.c

post-install:
	@${MKDIR} ${STAGEDIR}${SE_LOGDIR} ${STAGEDIR}${SE_DBDIR} ${STAGEDIR}${SE_PIDDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${FIND} ${WRKSRC} -name ${doc} -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR} \;
.endfor

.include <bsd.port.post.mk>
