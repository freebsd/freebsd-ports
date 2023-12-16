# PORTNAME block
PORTNAME=	motion
DISTVERSIONPREFIX=	release-
DISTVERSION=	4.6.0
CATEGORIES=	multimedia

# Maintainer block
MAINTAINER=	ports@blievers.net
COMMENT=	Motion detection application
WWW=		https://motion-project.github.io/

# License block
LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

# Dependencies
LIB_DEPENDS=	libwebp.so:graphics/webp \
		libmicrohttpd.so:www/libmicrohttpd

# USES block
USES=		autoreconf cpe gmake jpeg localbase pkgconfig
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	Motion-Project
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

# Standard bsd.port.mk variables
SUB_FILES=	pkg-message

# Options definitions
OPTIONS_DEFINE=		DOCS EXAMPLES FFMPEG MYSQL PGSQL SQLITE3 NLS

OPTIONS_DEFAULT=	WEBCAMD FFMPEG
OPTIONS_RADIO=		VIDEO
OPTIONS_RADIO_VIDEO=	BKTR PWCBSD WEBCAMD
OPTIONS_SUB=		yes

BKTR_DESC=		BKTR based TV capture cards

PWCBSD_DESC=		PWCBSD based Webcams

VIDEO_DESC=		Video capture driver (Netcam support only if none selected)
WEBCAMD_DESC=		Webcams using webcamd

BKTR_CONFIGURE_WITH=	bktr

FFMPEG_LIB_DEPENDS=	libavformat.so.60:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	pgsql

PWCBSD_BUILD_DEPENDS=	v4l_compat>=1.0.20060801:multimedia/v4l_compat
PWCBSD_RUN_DEPENDS=	pwcbsd>0:multimedia/pwcbsd
PWCBSD_CONFIGURE_WITH=	pwcbsd

SQLITE3_USES=		sqlite:3
SQLITE3_CONFIGURE_WITH=	sqlite3

WEBCAMD_BUILD_DEPENDS=	v4l_compat>=1.0.20060801:multimedia/v4l_compat
#  note: all configure --with-pwcbsd does is not shut off v4l support
WEBCAMD_CONFIGURE_WITH=	pwcbsd

.include <bsd.port.mk>
