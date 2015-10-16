# $FreeBSD$

PORTNAME=	btsync
PORTVERSION=	2.2.0
CATEGORIES=	net-p2p
MASTER_SITES=	https://download-cdn.getsyncapp.com/${PORTVERSION}/FreeBSD-${CONFIG_ARCH}/ \
		http://download-cdn.getsyncapp.com/${PORTVERSION}/FreeBSD-${CONFIG_ARCH}/
DISTNAME=	BitTorrent-Sync_freebsd_${CONFIG_ARCH}

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	Distributed peer-to-peer file syncing application

LICENSE=	EULA
LICENSE_NAME=	BitTorrent Sync
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	auto-accept

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	It is a binary-only program. Source code not available.

PLIST_SUB=	PORTNAME=${PORTNAME} USER=${USERS} GROUP=${GROUPS}
SUB_LIST=	PORTNAME=${PORTNAME} USER=${USERS} GROUP=${GROUPS}
SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

USERS=		${PORTNAME}
GROUPS=		${USERS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIG_ARCH=	x64
.else
CONFIG_ARCH=	${ARCH}
.endif

post-extract:
	${MKDIR} ${WRKSRC}/temp
	${MV} ${WRKSRC}/${PORTNAME} ${WRKSRC}/temp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/temp/btsync ${STAGEDIR}${PREFIX}/bin
	${WRKSRC}/temp/btsync --dump-sample-config > ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${REINPLACE_CMD} -e 's;^//\([[:space:]]*"storage_path"[[:space:]]*:[[:space:]]*\)"/.*",$$;\1"/var/db/${PORTNAME}",;' ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${REINPLACE_CMD} -e 's;^//\([[:space:]]*"pid_file"[[:space:]]*:[[:space:]]*"/var/run/${PORTNAME}/${PORTNAME}.pid",\)$$;\1;' ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

post-stage:
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.post.mk>
