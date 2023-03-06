PORTNAME=	softether
DISTVERSION=	5.02.5180-292
DISTVERSIONSUFFIX=	-g8c64dc0c
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	security net-vpn
PKGNAMESUFFIX=	5
DIST_SUBDIR=	${PORTNAME}

# Some patches are managed in my GitHub fork
PATCH_SITES=	https://github.com/metalefty/${GH_PROJECT}/commit/
PATCHFILES=	a672cffa.patch:-p1 \
		8b3c335c.patch:-p1 \
		f4e64e10.patch:-p1 \
		0dc45a98.patch:-p1 \
		0ace659a.patch:-p1 \
		d560d962.patch:-p1 \
		c4a8b52a.patch:-p1

MAINTAINER=	meta@FreeBSD.org
COMMENT=	SoftEther VPN 5 (Developer Edition)
WWW=		https://www.softether.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsodium.so:security/libsodium

USES+=		cmake:noninja compiler:c11 iconv:wchar_t localbase:ldflags \
		ncurses pkgconfig readline ssl
USE_RC_SUBR=	softether_bridge softether_client softether_server \
		softether_trafficserver
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	SoftEtherVPN
GH_PROJECT=	SoftEtherVPN
GH_TUPLE=	SoftEtherVPN:libhamcore:2951ae5:libhamcore/src/libhamcore \
		BLAKE2:BLAKE2:b52178a:BLAKE2/3rdparty/BLAKE2 \
		cxong:tinydir:ec6bff2:tinydir/3rdparty/tinydir

CMAKE_ARGS+=	-DSE_DBDIR="${SE_DBDIR}" \
		-DSE_LOGDIR="${SE_LOGDIR}" \
		-DSE_PIDDIR="${SE_PIDDIR}" \
		-DSE_TAGNAME="${GH_TAGNAME}/freebsd"

CFLAGS+=	-I${LOCALBASE}/include/cpu_features

OPTIONS_DEFINE=	DOCS DEBUG

PORTDOCS=		DISCLAIMER.md WARNING.TXT
CONFLICTS_INSTALL=	softether-4.[0-9]* softether-devel-4.[0-9]*

SE_DBDIR?=	/var/db/${PORTNAME}
SE_LOGDIR?=	/var/log/${PORTNAME}
SE_PIDDIR?=	/var/run/${PORTNAME}
PLIST_SUB=	SE_DBDIR="${SE_DBDIR}" \
		SE_LOGDIR="${SE_LOGDIR}" \
		SE_PIDDIR="${SE_PIDDIR}"
SUB_LIST=	SE_DBDIR="${SE_DBDIR}" \
		SE_LOGDIR="${SE_LOGDIR}" \
		SE_PIDDIR="${SE_PIDDIR}"
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

# CMAKE_BUILD_TYPE is automatically set by Mk/Uses/cmake.mk
# just set WITH_DEBUG=yes, CMAKE_ARGS+=-DCMAKE_BUILD_TYPE=Debug takes no effect.
.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG=	yes
.endif

.include <bsd.port.pre.mk>

# devel/cpu_features not available on these archs, see devel/cpu_features/Makefile
.if (${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7 || \
     ${ARCH} == mips || ${ARCH} == mips64)
# skip cpu_features when devel/cpu_features is not available
CMAKE_ARGS+=	-DSKIP_CPU_FEATURES=1
.else
BUILD_DEPENDS+=	${LOCALBASE}/include/cpu_features/cpu_features_macros.h:devel/cpu_features
LIB_DEPENDS+=	libcpu_features.so:devel/cpu_features
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${SE_LOGDIR} ${STAGEDIR}${SE_DBDIR} ${STAGEDIR}${SE_PIDDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${FIND} ${WRKSRC} -name ${doc} -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR} \;
.endfor

.include <bsd.port.post.mk>
