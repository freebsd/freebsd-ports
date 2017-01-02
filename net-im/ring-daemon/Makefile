# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	ring-daemon
PORTVERSION=	0.160516
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-im net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Daemon part of the Ring VoIP SIP phone and IM

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp \
		libjsoncpp.so:devel/jsoncpp \
		libpcre.so:devel/pcre \
		libupnp.so:devel/upnp \
		libopendht.so:devel/opendht \
		libgnutls.so:security/gnutls \
		libavcodec.so:multimedia/ffmpeg \
		libpulse.so:audio/pulseaudio \
		libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libuuid.so:misc/e2fsprogs-libuuid

USE_GITHUB=	yes
GH_TUPLE+=	savoirfairelinux:ring-daemon:56ec56f
GH_TUPLE+=	pjsip:pjproject:2.4.5:pj

CONFIGURE_ARGS=	--without-gsm \
		--enable-video \
		--enable-ipv6

USES=		autoreconf compiler:c++14-lang gmake libtool pkgconfig
USE_GNOME=	glib20 gtk20 cairo gdkpixbuf2
USE_XORG=	x11 xscrnsaver
USE_GL=		gl
USE_QT5=	core gui network xml opengl sql sql-sqlite3_run widgets svg \
		concurrent buildtools_build linguisttools_build
GNU_CONFIGURE=	yes
MYFLAGS=	-I${WRKSRC}/contrib/native/pjproject/pjlib/include -I${LOCALBASE}/include -DPJ_LINUX -I${LOCALBASE}/include/jsoncpp
CFLAGS+=	${MYFLAGS}
CPPFLAGS+=	${MYFLAGS}
CXXFLAGS+=	${MYFLAGS}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DBUS
OPTIONS_DEFAULT=DBUS
DBUS_CONFIGURE_OFF=	--without-dbus
DBUS_CONFIGURE_ON=	--with-dbus
DBUS_LIB_DEPENDS=	\
	libdbus-1.so:devel/dbus \
	libdbus-c++-1.so:devel/dbus-c++
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1002000
BROKEN=		does not build
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/contrib/native
	@${MV} ${WRKDIR}/pjproject-2.4.5 ${WRKSRC}/contrib/native/
post-patch:
	@${REINPLACE_CMD} -e 's|PJPROJECT_OPTIONS)|PJPROJECT_OPTIONS) CPPFLAGS=-I${LOCALBASE}/include/ CFLAGS="-I${LOCALBASE}/include/ -fPIC"|g' \
		${WRKSRC}/contrib/src/pjproject/rules.mak
	@${REINPLACE_CMD} -e 's|ringtonePath_ = "/usr/share|ringtonePath_ = "${LOCALBASE}/share|g' \
		${WRKSRC}/src/account.cpp
pre-configure:
	@(cd ${WRKSRC} && \
	    ${ECHO} "===> Building the custom version of pjsip" && \
	    cd contrib/native && \
	    ../bootstrap && \
	    ${GMAKE} .pjproject)
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libring.so

.include <bsd.port.post.mk>
