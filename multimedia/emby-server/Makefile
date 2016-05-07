# Created by: Ben Woods <woodsb02@gmail.com>
# $FreeBSD$

PORTNAME=	emby-server
PORTVERSION=	3.0.5913
CATEGORIES=	multimedia

MAINTAINER=	woodsb02@gmail.com
COMMENT=	Home media server built using mono and other open source technologies

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libsqlite3.so:databases/sqlite3

CONFLICTS_INSTALL=	mediabrowser

USE_GITHUB=	yes
GH_ACCOUNT=	MediaBrowser
GH_PROJECT=	Emby

USES=		mono pkgconfig

USE_RC_SUBR=	${PORTNAME}
RC_NAME=	emby_server
SUB_LIST=	PORTNAME=${PORTNAME} USER=${USERS} GROUP=${GROUPS} RC_NAME=${RC_NAME}
USERS=		emby
GROUPS=		emby

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
X11_LIB_DEPENDS=libMagickWand-6.so:graphics/ImageMagick
X11_LIB_DEPENDS_OFF=libMagickWand-6.so:graphics/ImageMagick-nox11

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/xbuild /t:build /p:Configuration="Release Mono" \
			/p:Platform="Any CPU" MediaBrowser.Mono.sln)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/emby-server
	(cd ${WRKSRC}/MediaBrowser.Server.Mono/bin/Release\ Mono && \
		${ECHO_MSG} "Deleting the following non-FreeBSD library files:" && \
		${FIND} -E . -iregex '(.*\.dylib|.*libwebp.*|.*sqlite3.*|.*.dylib.*|MediaInfo\.dll)' -print -delete && \
		${FIND} . -type d -empty -print -delete && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/emby-server)

.include <bsd.port.mk>
