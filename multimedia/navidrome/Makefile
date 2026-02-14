PORTNAME=	navidrome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.60.0
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/:assets
# For instructions on how to create assets:
#   https://github.com/DtxdF/port-assets-makejails/tree/main/navidrome
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}:assets \
		${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.vendor${EXTRACT_SUFX}:assets

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Modern Music Server and Streamer compatible with Subsonic/Airsonic
WWW=		https://www.navidrome.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

LIB_DEPENDS=	libtag.so:audio/taglib
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cpe go:1.25+,modules nodejs:24,build pkgconfig

USE_GITHUB=	yes

USE_RC_SUBR=	${PORTNAME}

GO_ENV+=	CGO_CFLAGS_ALLOW="--define-prefix"
GO_BUILDFLAGS=	-ldflags="\
			-X github.com/navidrome/navidrome/consts.gitSha=${GITID} \
			-X github.com/navidrome/navidrome/consts.gitTag=${GH_TAGNAME}" \
		-tags=netgo

SUB_FILES+=	config.toml.sample pkg-message
SUB_LIST+=	NAVIDROMEGROUP=${NAVIDROME_GROUP} \
		NAVIDROMEUSER=${NAVIDROME_USER} \
		PORTNAME=${PORTNAME}

USERS=		${NAVIDROME_USER}
GROUPS=		${NAVIDROME_GROUP}

GITID=		6fb4cd2

NAVIDROME_USER=		www
NAVIDROME_GROUP=	www

post-extract:
	@${MKDIR} ${WRKSRC}/vendor
	@cd ${WRKDIR}/${PORTNAME}-vendor && ${COPYTREE_SHARE} . ${WRKSRC}/vendor
	@${MKDIR} ${WRKSRC}/ui/build
	@cd ${WRKDIR}/${PORTNAME}-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/ui/build

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/music
	${INSTALL_DATA} ${WRKDIR}/config.toml.sample \
		${STAGEDIR}${ETCDIR}/config.toml.sample

.include <bsd.port.mk>
