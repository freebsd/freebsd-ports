# Created by: KalleDK <plexmaintainer@k-moeller.dk>
# $FreeBSD$

PORTNAME=	plexmediaserver
PORTVERSION?=	1.19.1.2701
DISTVERSIONSUFFIX?=6327e27bf
PORTREVISION?=	0
CATEGORIES=	multimedia
MASTER_SITES?=	https://downloads.plex.tv/plex-media-server-new/${DISTVERSION}-${DISTVERSIONSUFFIX}/freebsd/
DISTNAME?=	PlexMediaServer-${DISTVERSION}-${DISTVERSIONSUFFIX}-FreeBSD-${ARCH}

MAINTAINER?=	feld@FreeBSD.org
COMMENT=	Plex Media Server component

USES=		cpe tar:bzip2
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/PlexMediaServer-${PORTVERSION}-${DISTVERSIONSUFFIX}

CPE_VENDOR=	plex
CPE_PRODUCT=	plex_media_server
CPE_VERSION=	${PORTVERSION:R}

USE_RC_SUBR?=	${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST?=	PORTNAME=${PORTNAME} DATADIR=${DATADIR} USERS=${USERS} GROUPS=${GROUPS}

USERS=		plex
GROUPS=		${USERS}
BUNDLE_LIBS=	yes

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	binary-only program, source code not available

OPTIONS_DEFINE=	RELAY
OPTIONS_DEFAULT=	RELAY
OPTIONS_SUB=	yes
RELAY_DESC=	Install Plex Relay daemon

.include <bsd.port.pre.mk>

post-patch:
	# binaries don't come pre-stripped
	${FIND} ${WRKSRC}/Resources -type f -name '*.so' -exec ${STRIP_CMD} {} \+
	${FIND} ${WRKSRC} ${WRKSRC}/Resources -type f -name 'Plex*' -depth 1 -exec ${STRIP_CMD} {} \+
	${FIND} ${WRKSRC} -depth 1 -type f -name 'lib*' -exec ${STRIP_CMD} {} \+

post-patch-RELAY-off:
	${RM} ${WRKSRC}/Plex\ Relay

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR})
	# Workaround for space in binary name
	${INSTALL} -lrs ${STAGEDIR}/${DATADIR}/Plex\ Media\ Server ${STAGEDIR}/${DATADIR}/Plex_Media_Server

post-install:
	@${CHMOD} 555 ${STAGEDIR}/${DATADIR}/CrashUploader ${STAGEDIR}/${DATADIR}/Plex*
	@${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.post.mk>
