# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxul
DISTVERSION=	38.7.1
PORTREVISION=	1
CATEGORIES?=	www devel
MASTER_SITES=	MOZILLA/firefox/releases/${DISTVERSION}esr/source \
		MOZILLA/firefox/candidates/${DISTVERSION}esr-candidates/build1/source
DISTNAME=	firefox-${DISTVERSION}esr.source

MAINTAINER?=	gecko@FreeBSD.org
COMMENT?=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

BUILD_DEPENDS=	nspr>=4.10.10:${PORTSDIR}/devel/nspr \
		nss>=3.19.2.1:${PORTSDIR}/security/nss \
		libevent2>=2.0.21_2:${PORTSDIR}/devel/libevent2 \
		soundtouch>=1.8.0:${PORTSDIR}/audio/soundtouch \
		harfbuzz>=0.9.34:${PORTSDIR}/print/harfbuzz \
		graphite2>=1.2.4:${PORTSDIR}/graphics/graphite2 \
		libvorbis>=1.3.5,3:${PORTSDIR}/audio/libvorbis \
		libvpx>=1.3.0:${PORTSDIR}/multimedia/libvpx \
		sqlite3>=3.8.9:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		autoconf-2.13:${PORTSDIR}/devel/autoconf213 \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
#		opus>=1.1:${PORTSDIR}/audio/opus \

LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

WRKSRC=		${WRKDIR}/mozilla-esr38
CONFLICTS_INSTALL=	libxul-1.9.*

USE_QT5=	# empty
QT_NONSTANDARD=	yes
USE_GL=		gl
USES=		pathfix tar:bzip2
MAKE_ENV=	SKIP_GRE_REGISTRATION=1 mozappdir=${PREFIX}/lib/${MOZILLA}
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}
USE_LDCONFIG=	${PREFIX}/lib/${MOZILLA}

MOZ_OPTIONS?=	--enable-application=xulrunner
USE_GECKO=	gecko
CPE_PRODUCT=	firefox_esr
MOZILLA_EXEC_NAME=xulrunner
USE_MOZILLA=	-opus
MOZILLA_PLIST_DIRS=	bin include lib share/idl libdata
MOZ_PKGCONFIG_FILES=	libxul-embedding libxul mozilla-js \
			mozilla-plugin

OPTIONS_DEFAULT=	GTK2

OPTIONS_SINGLE+=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

.if ${USE_MOZILLA:M-nss}
MOZ_PKGCONFIG_FILES+=	mozilla-nss
.endif

.if ${PORT_OPTIONS:MALSA}
RUN_DEPENDS+=	alsa-lib>=1.0.27.2_1:${PORTSDIR}/audio/alsa-lib
.endif

.if ! ${PORT_OPTIONS:MBUNDLED_CAIRO}
BUILD_DEPENDS+=	cairo>=1.12.16_1,2:${PORTSDIR}/graphics/cairo
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
RUN_DEPENDS+=	gstreamer1-libav>=1.2.4_1:${PORTSDIR}/multimedia/gstreamer1-libav
.endif

.if ${PORT_OPTIONS:MGTK3}
BUILD_DEPENDS+=	gtk3>=3.14.6:${PORTSDIR}/x11-toolkits/gtk30
.endif

post-patch:
	@${REINPLACE_CMD} -e '/MOZPNG/s/=[0-9]*/=10511/' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/xulrunner/stub/nsXULStub.cpp

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

post-build:
	@${REINPLACE_CMD} -e "s|\(Libs:.*\)\($$\)|\1 -Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}\2| ; \
		s|%sdkdir%|%sdkdir%/sdk|g ; \
		s|%%MOZ_LIBDIR%%|${PREFIX}/lib/${MOZILLA}|g" \
		${WRKSRC}/xulrunner/installer/*.pc.in || ${TRUE}

.include <bsd.port.post.mk>
