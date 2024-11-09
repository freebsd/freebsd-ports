PORTNAME=	rslsync
DISTVERSION=	2.8.1.1390
CATEGORIES=	net-p2p
MASTER_SITES=	https://download-cdn.resilio.com/${DISTVERSION}/freebsd/${CONFIG_ARCH}/0/
DISTNAME=	resilio-sync_freebsd_${CONFIG_ARCH}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	arcade@b1t.name
COMMENT=	Distributed peer-to-peer file syncing application
WWW=		https://www.resilio.com/

LICENSE=	EULA
LICENSE_NAME=	Resilio Sync
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	binary-only program, source code not available

USE_RC_SUBR=	rslsync

CONFLICTS_INSTALL=	rslsync-beta

NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	GROUP=${GROUPS} \
		USER=${USERS}

NO_WRKSUBDIR=	yes

USERS=		rslsync
GROUPS=		${USERS}

PLIST_SUB=	GROUP=${GROUPS} \
		USER=${USERS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIG_ARCH=	x64
.else
CONFIG_ARCH=	${ARCH}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rslsync ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/var/db/rslsync
	${STAGEDIR}${PREFIX}/bin/rslsync --nodaemon \
		--storage ${WRKSRC} --dump-sample-config \
		> ${STAGEDIR}${PREFIX}/etc/rslsync.conf.sample
	${REINPLACE_CMD} -e \
		's;^//\([[:space:]]*"storage_path"[[:space:]]*:[[:space:]]*\)"/.*",$$;\1"/var/db/rslsync",;' \
		-e \
		's;^//\([[:space:]]*"pid_file"[[:space:]]*:[[:space:]]*\)"/.*",$$;\1"/var/run/rslsync/rslsync.pid",;' \
		${STAGEDIR}${PREFIX}/etc/rslsync.conf.sample

maintainer-makesum:
	for arch in ${ONLY_FOR_ARCHS}; do \
		${MAKE} DISTINFO_FILE=/dev/stdout ARCH=$$arch makesum; \
	done | ${AWK} 'BEGIN{TS=0}/TIMESTAMP/{if(TS==0){print;TS=1};next}/S(HA256|IZE)/{print}' \
		> ${DISTINFO_FILE}

.include <bsd.port.post.mk>
