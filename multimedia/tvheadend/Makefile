# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tvheadend
PORTVERSION=	4.2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	decke@FreeBSD.org
COMMENT=	TV streaming server supporting DVB, IPTV, SAT>IP and more

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libcurl.so:ftp/curl \
		liburiparser.so:net/uriparser
RUN_DEPENDS=	dtv-scan-tables>=0:multimedia/dtv-scan-tables

BROKEN_mips=		fails to configure: No C compiler found
BROKEN_mips64=		fails to configure: No C compiler found
BROKEN_powerpc64=	fails to configure: No C compiler found

USES=		gettext gmake pkgconfig python shebangfix ssl
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	${WRKSRC}/Autobuild.sh \
		${WRKSRC}/configure \
		${WRKSRC}/support/apt-update \
		${WRKSRC}/support/configure.inc \
		${WRKSRC}/support/getmuxlist \
		${WRKSRC}/support/version

TVHUSER?=	tvheadend
TVHGROUP?=	tvheadend

USERS=		${TVHUSER}
GROUPS=		${TVHGROUP} webcamd
SUB_LIST+=	TVHUSER="${TVHUSER}" \
		TVHGROUP="${TVHGROUP}"

CONFIGURE_ENV+=	PLATFORM=freebsd
CONFIGURE_ARGS+=--disable-dvbscan --disable-zlib --disable-hdhomerun_static \
		--disable-bintray_cache --disable-ffmpeg_static --disable-pie
CFLAGS+=	-I${LOCALBASE}/include -Wno-conversion -Wno-int-to-pointer-cast
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo -lssl -lcrypto -lz

OPTIONS_DEFINE=	AVAHI DVBCSA HDHOMERUN INOTIFY TRANSCODING XMLTV
OPTIONS_DEFAULT=DVBCSA HDHOMERUN INOTIFY

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app

DVBCSA_DESC=		Replace internal ffdecsa with dvbcsa
DVBCSA_LIB_DEPENDS=	libdvbcsa.so:multimedia/libdvbcsa
DVBCSA_CONFIGURE_ENABLE=	dvbcsa

HDHOMERUN_DESC=		Native support for HDHomeRun network tuners
HDHOMERUN_LIB_DEPENDS=	libhdhomerun.so:multimedia/libhdhomerun
HDHOMERUN_CONFIGURE_ENABLE=	hdhomerun_client

INOTIFY_DESC=		File system notifications support
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_CONFIGURE_ENABLE=	inotify
INOTIFY_LDFLAGS=	-linotify

TRANSCODING_DESC=	Transcoding for mobile and web clients
TRANSCODING_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
TRANSCODING_CONFIGURE_ENABLE=	libav

XMLTV_RUN_DEPENDS=	p5-xmltv>=0:textproc/p5-xmltv

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's|-ldl||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|-Werror||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/tvheadend

.include <bsd.port.post.mk>
