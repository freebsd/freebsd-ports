PORTNAME=	kanidm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.3
CATEGORIES=	security net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple and secure identity management platform ${${FLAVOR}_COMMENT}
WWW=		https://kanidm.com \
		https://github.com/kanidm/kanidm/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

IGNORE_FreeBSD_13=		Does not build on FreeBSD 13.x due to OpenSSL 1.1.1
ONLY_FOR_ARCHS=	aarch64 amd64

FLAVORS=	client server
FLAVOR?=	${FLAVORS:[1]}
client_PKGNAMESUFFIX=	-client
client_COMMENT=		(client only)
client_PLIST=	${.CURDIR}/pkg-plist.client
server_PKGNAMESUFFIX=	-server
server_COMMENT=		(server only)
server_PLIST=	${.CURDIR}/pkg-plist.server

USES=		cargo ssl llvm
USE_GITHUB=	yes

MAKE_ENV=    LIBCLANG_PATH=${LLVM_PREFIX}/lib

.if ${FLAVOR} == server
CARGO_BUILD_ARGS=	-p daemon
USE_RC_SUBR=	kanidmd
.endif

.if ${FLAVOR} == client
CARGO_BUILD_ARGS=	-p kanidm_tools -p kanidm_unix_int -p nss_kanidm -p pam_kanidm
USE_RC_SUBR=	kanidm_unixd kanidm_unixd_tasks
.endif

CARGO_INSTALL=	no
CARGO_ENV=	KANIDM_BUILD_PROFILE=release_freebsd

CLIENT_CACHEDIR=/var/cache/kanidm-unixd
CLIENT_LIBDIR=/var/lib/kanidm-unixd
CLIENT_RUNDIR=/var/run/kanidm-unixd

SERVER_LIBDIR=/var/lib/kanidmd
SERVER_RUNDIR=/var/run/kanidmd

.if ${FLAVOR} == server
USERS=		kanidmd
GROUPS=		kanidmd

SUB_LIST=	USER=${USERS} \
		GROUP=${GROUPS} \
		ETCDIR=${PREFIX}/etc/kanidm \
		RUNDIR=/var/run/kanidmd \
		LIBDIR=/var/lib/kanidmd
.endif

.if ${FLAVOR} == client
USERS=		kanidm
GROUPS=		kanidm

SUB_LIST=	USER=${USERS} \
		GROUP=${GROUPS} \
		ETCDIR=${PREFIX}/etc/kanidm \
		RUNDIR=/var/run/kanidm-unixd \
		CACHEDIR=/var/cache/kanidm-unixd \
		LIBDIR=/var/lib/kanidm-unixd
.endif

do-install:
.if ${FLAVOR} == server
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/kanidmd ${STAGEDIR}${PREFIX}/libexec
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${SERVER_LIBDIR}
	${MKDIR} ${STAGEDIR}${SERVER_RUNDIR}
.endif

.if ${FLAVOR} == client
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/kanidm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/kanidm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/kanidm-unix ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/kanidm_ssh_authorizedkeys ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/kanidm_ssh_authorizedkeys_direct ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/kanidm_unixd ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/kanidm_unixd_tasks ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_LIB} ${WRKDIR}/target/release/libnss_kanidm.so ${STAGEDIR}${PREFIX}/lib/nss_kanidm.so.1
	${INSTALL_LIB} ${WRKDIR}/target/release/libpam_kanidm.so ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${CLIENT_CACHEDIR}
	${MKDIR} ${STAGEDIR}${CLIENT_LIBDIR}
	${MKDIR} ${STAGEDIR}${CLIENT_RUNDIR}
.endif

.include <bsd.port.mk>
