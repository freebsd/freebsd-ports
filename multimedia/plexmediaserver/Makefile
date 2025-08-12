PORTNAME=	plexmediaserver
DISTVERSION?=	1.42.1.10060
DISTVERSIONSUFFIX?=	4e8b05daf
CATEGORIES=	multimedia
MASTER_SITES?=	https://downloads.plex.tv/plex-media-server-new/${DISTVERSION}-${DISTVERSIONSUFFIX}/freebsd/
DISTNAME?=	PlexMediaServer-${DISTVERSION}-${DISTVERSIONSUFFIX}-FreeBSD-${ARCH}

MAINTAINER=	b.shertenlieb@yahoo.com
COMMENT=	Plex Media Server component
WWW=		https://plex.tv

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_TEXT=	This program is NOT in public domain.\
		Terms Of Service available at www.Plex.tv
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	binary-only program, source code not available

USES=		cpe tar:bzip2

CPE_VENDOR=	plex
CPE_PRODUCT=	media_server
CPE_VERSION=	${DISTVERSION:R}

USE_RC_SUBR?=	${PORTNAME}
BUNDLE_LIBS=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST?=	PORTNAME=${PORTNAME}
SUB_LIST+=	DATADIR=${DATADIR} USERS=${USERS} GROUPS=${GROUPS}

WRKSRC=		${WRKDIR}/PlexMediaServer-${DISTVERSION}-${DISTVERSIONSUFFIX}

USERS=		plex
GROUPS=		${USERS}

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
