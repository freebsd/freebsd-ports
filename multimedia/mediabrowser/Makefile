# $FreeBSD$

PORTNAME=	mediabrowser
PORTVERSION=	3.0.5416.0
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
GH_COMMIT=	14a81fb
GH_TAGNAME=	${PORTVERSION}

USES=		mono pkgconfig

USE_RC_SUBR=	mediabrowser
SUB_LIST=	SUPPORT_PATH=${SUPPORT_PATH} USERS=${USERS} GROUPS=${GROUPS}
USERS=		mediabrowser
GROUPS=		mediabrowser
SUPPORT_PATH?=	${PREFIX}/mediabrowserdata

do-build:
	(cd ${WRKSRC} && \
		${LOCALBASE}/bin/xbuild /t:build /p:Configuration="Release Mono" \
			/p:Platform="Any CPU" MediaBrowser.Mono.sln)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mediabrowser
	(cd ${WRKSRC}/MediaBrowser.Server.Mono/bin/Release\ Mono && \
		${RM} -rv ./MediaInfo && \
		${RM} -rv ./libwebp && \
		${RM} -rv ./sqlite3 && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/mediabrowser)

.include <bsd.port.mk>
