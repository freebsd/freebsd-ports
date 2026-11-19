PORTNAME=	softether
DISTVERSION=	5.2.5190
PORTEPOCH=	2
CATEGORIES=	security net-vpn
PKGNAMESUFFIX=	5
DIST_SUBDIR=	${PORTNAME}

# Some patches are managed in my GitHub fork
PATCH_SITES=	https://github.com/metalefty/${GH_PROJECT}/commit/
PATCHFILES=	d462b58.patch:-p1 \
		7a7afe2.patch:-p1 \
		7a026ca.patch:-p1 \
		04ba4cd.patch:-p1

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
GH_TUPLE=	BLAKE2:BLAKE2:b52178a3:blake2/3rdparty/BLAKE2 \
		cxong:tinydir:ec6bff20:tinydir/3rdparty/tinydir \
		google:cpu_features:ba4bffa8:cpu_features/src/Mayaqua/3rdparty/cpu_features \
		open-quantum-safe:liboqs:94b421eb:liboqs/src/Mayaqua/3rdparty/liboqs \
		open-quantum-safe:oqs-provider:7b8df261:oqsprovider/src/Mayaqua/3rdparty/oqs-provider \
		SoftEtherVPN:libhamcore:fb8d4978:libhamcore/src/libhamcore

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
		-DSE_DBDIR="${SE_DBDIR}" \
		-DSE_LOGDIR="${SE_LOGDIR}" \
		-DSE_PIDDIR="${SE_PIDDIR}" \
		-DSE_TAGNAME="${GH_TAGNAME}/freebsd"

CFLAGS+=	-I${LOCALBASE}/include/cpu_features

OPTIONS_DEFINE=	DOCS

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

.include <bsd.port.pre.mk>

# devel/cpu_features not available on these archs, see devel/cpu_features/Makefile
.if (${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7)
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

x-maintainer-tuples:
	@submodules2tuple -s -b ${DISTVERSION} https://github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.post.mk>
