# $FreeBSD$

PORTNAME=	mediabrowser
PORTVERSION=	3.0.5464.40000
CATEGORIES=	multimedia

MAINTAINER=	woodsb02@gmail.com
COMMENT=	Home media server built using mono and other open source technologies

LICENSE=	GPLv2

LIB_DEPENDS=	libavformat.so:${PORTSDIR}/multimedia/ffmpeg \
		libgdiplus.so:${PORTSDIR}/x11-toolkits/libgdiplus \
		libmediainfo.so:${PORTSDIR}/multimedia/libmediainfo \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libwebp.so:${PORTSDIR}/graphics/webp

USE_GITHUB=	yes
GH_ACCOUNT=	MediaBrowser
GH_PROJECT=	MediaBrowser
GH_COMMIT=	1616e34
GH_TAGNAME=	${PORTVERSION}

USES=		mono pkgconfig

USE_RC_SUBR=	mediabrowser
SUB_LIST=	PORTNAME=${PORTNAME} USER=${USERS} GROUP=${GROUPS}
USERS=		mediabrowser
GROUPS=		mediabrowser

do-build:
	(cd ${WRKSRC} && \
		${LOCALBASE}/bin/xbuild /t:build /p:Configuration="Release Mono" \
			/p:Platform="Any CPU" MediaBrowser.Mono.sln)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mediabrowser
	(cd ${WRKSRC}/MediaBrowser.Server.Mono/bin/Release\ Mono && \
		${ECHO_MSG} "Deleting the following non-FreeBSD library files:" && \
		${FIND} -E . -iregex '(.*\.dylib|.*libwebp.*|.*sqlite3.*|.*.dylib.*|MediaInfo\.dll)' -print -delete && \
		${FIND} . -type d -empty -print -delete && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/mediabrowser)

.include <bsd.port.mk>
