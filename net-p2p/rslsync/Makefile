# $FreeBSD$

PORTNAME=	rslsync
PORTVERSION=	2.6.4
CATEGORIES=	net-p2p
MASTER_SITES=	https://download-cdn.resilio.com/${PORTVERSION}/FreeBSD-${CONFIG_ARCH}/ \
		http://download-cdn.resilio.com/${PORTVERSION}/FreeBSD-${CONFIG_ARCH}/
DISTNAME=	resilio-sync_freebsd_${CONFIG_ARCH}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	arcade@b1t.name
COMMENT=	Distributed peer-to-peer file syncing application

LICENSE=	EULA
LICENSE_NAME=	Resilio Sync
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	It is a binary-only program. Source code not available.

CONFLICTS_INSTALL=	rslsync-beta

NO_WRKSUBDIR=	yes

PLIST_SUB=	USER=${USERS} GROUP=${GROUPS}
SUB_LIST=	USER=${USERS} GROUP=${GROUPS}
SUB_FILES=	pkg-message
USE_RC_SUBR=	rslsync

USERS=		rslsync
GROUPS=		${USERS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIG_ARCH=	x64
.else
CONFIG_ARCH=	${ARCH}
.endif

do-build:
	${WRKSRC}/rslsync --nodaemon --storage ${WRKSRC} --dump-sample-config > ${WRKSRC}/rslsync.conf.sample
	${REINPLACE_CMD} -e 's;^//\([[:space:]]*"storage_path"[[:space:]]*:[[:space:]]*\)"/.*",$$;\1"/var/db/rslsync",;' ${WRKSRC}/rslsync.conf.sample
	${REINPLACE_CMD} -e 's;^//\([[:space:]]*"pid_file"[[:space:]]*:[[:space:]]*\)"/.*",$$;\1"/var/run/rslsync/rslsync.pid",;' ${WRKSRC}/rslsync.conf.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rslsync ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/rslsync.conf.sample ${STAGEDIR}${PREFIX}/etc
	${MKDIR} ${STAGEDIR}/var/db/rslsync

maintainer-makesum:
	for arch in ${ONLY_FOR_ARCHS}; do ${MAKE} DISTINFO_FILE=/dev/stdout ARCH=$$arch makesum; done | ${AWK} '$$1 != "TIMESTAMP" || NR == 1' > ${DISTINFO_FILE}

.include <bsd.port.post.mk>
