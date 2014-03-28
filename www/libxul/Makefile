# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxul
DISTVERSION=	24.3.0
CATEGORIES?=	www devel
MASTER_SITES=	MOZILLA/firefox/releases/${DISTVERSION}esr/source \
		https://ftp.mozilla.org/pub/mozilla.org/firefox/candidates/${DISTVERSION}esr-candidates/build1/source/
DISTNAME=	firefox-${DISTVERSION}esr.source

MAINTAINER?=	gecko@FreeBSD.org
COMMENT?=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

BUILD_DEPENDS=	nspr>=4.10.2:${PORTSDIR}/devel/nspr \
		nss>=3.15.4:${PORTSDIR}/security/nss \
		sqlite3>=3.7.17:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		cairo>=1.10.2_1,1:${PORTSDIR}/graphics/cairo \
		harfbuzz>=0.9.16:${PORTSDIR}/print/harfbuzz \
		libvorbis>=1.3.4:${PORTSDIR}/audio/libvorbis \
		opus>=1.1:${PORTSDIR}/audio/opus \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

WRKSRC=		${WRKDIR}/mozilla-esr24
CONFLICTS=	libxul-1.9.*

USE_AUTOTOOLS=	autoconf213:env
USE_PYTHON_BUILD=2
WANT_GNOME=	yes
USE_QT4=	# empty
QT_NONSTANDARD=	yes
WANT_PERL=	yes
ALL_TARGET=	default
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GL=		gl
USES=		dos2unix
DOS2UNIX_FILES=	media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp
MAKE_ENV=	SKIP_GRE_REGISTRATION=1 mozappdir=${PREFIX}/lib/${MOZILLA}
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}
USE_LDCONFIG=	${PREFIX}/lib/${MOZILLA}

MOZ_OPTIONS?=	--enable-application=xulrunner
MOZ_EXTENSIONS=	default,cookie,permissions
USE_GECKO=	gecko
OBJDIR_BUILD=	# in-tree build broken after bug 789837
MOZILLA_EXEC_NAME=xulrunner
USE_MOZILLA=	# empty
MOZILLA_PLIST_DIRS=	bin include lib share/idl
PLIST_DIRSTRY=	share/idl
MOZ_PKGCONFIG_FILES=	libxul-embedding libxul mozilla-js \
			mozilla-plugin

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

.if ${USE_MOZILLA:M-nss}
MOZ_PKGCONFIG_FILES+=	mozilla-nss
.endif

.if ${PORT_OPTIONS:MALSA}
BUILD_DEPENDS+=	alsa-lib>=1.0.27.2_1:${PORTSDIR}/audio/alsa-lib
.endif

post-patch:
	@${REINPLACE_CMD} -e '/MOZPNG/s/=[0-9]*/=10511/' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/xulrunner/stub/nsXULStub.cpp

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${WRKSRC}/js/src/ && ${AUTOCONF})

post-build:
	@${REINPLACE_CMD} -e "s|\(Libs:.*\)\($$\)|\1 -Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}\2| ; \
		s|%sdkdir%|%sdkdir%/sdk|g ; \
		s|%%MOZ_LIBDIR%%|${PREFIX}/lib/${MOZILLA}|g" \
		${WRKSRC}/xulrunner/installer/*.pc.in || ${TRUE}

.include <bsd.port.post.mk>
