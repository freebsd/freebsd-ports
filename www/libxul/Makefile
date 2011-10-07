# New ports collection makefile for:	xulrunner
# Date created:		2006-02-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxul
DISTVERSION=	1.9.2.23
CATEGORIES?=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	firefox/releases/3.6.23/source
DISTNAME=	firefox-3.6.23.source

MAINTAINER?=	gecko@FreeBSD.org
COMMENT?=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

WRKSRC=		${WRKDIR}/mozilla-1.9.2
CONFLICTS=	mozilla-[0-9]*
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/bin lib/${MOZILLA}/idl \
			lib/${MOZILLA}/include lib/${MOZILLA}/lib

USE_AUTOTOOLS=	autoconf213
WANT_GNOME=	yes
WANT_PERL=	yes
ALL_TARGET=	default
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	SKIP_GRE_REGISTRATION=1 mozappdir=${PREFIX}/lib/${MOZILLA}
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}
USE_LDCONFIG=	${PREFIX}/lib/${MOZILLA}

PORT_MOZCONFIG=	${WRKSRC}/xulrunner/config/mozconfig
MOZ_OPTIONS?=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--disable-javaxpcom --enable-canvas \
		--enable-system-cairo --disable-updater \
		--disable-necko-wifi --disable-ipc
MOZ_EXTENSIONS=	default,cookie,permissions
OPTIONS=	# Empty, used for generic gecko OPTIONS
USE_GECKO_OPTIONS=	java debug logging optimized_cflags
USE_GECKO=	gecko
MOZILLA_EXEC_NAME=xulrunner
MOZ_TOOLKIT=	cairo-gtk2
USE_MOZILLA=	-png -nss -dbm -jpeg
MOZ_PKGCONFIG_FILES=	libxul-embedding libxul mozilla-gtkmozembed-embedding \
		mozilla-gtkmozembed mozilla-js mozilla-nss mozilla-plugin

OPTIONS=	DBUS "Enable D-BUS support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
EXTRA_PATCHES=	${FILESDIR}/releng6_pulseaudio
.else
EXTRA_PATCHES=	${FILESDIR}/libsydney_oss
.endif

.if ${ARCH} == powerpc64
.if ${OSVERSION} < 900033
BROKEN=		Needs binutils 2.17.50 to build
.else
CONFIGURE_ENV+=	UNAME_m="powerpc64"
CFLAGS+=	-mminimal-toc
.endif
.endif

.if defined(WITHOUT_DBUS)
MOZ_OPTIONS+=	--disable-dbus --disable-libnotify
.else
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		notify.4:${PORTSDIR}/devel/libnotify
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
	    	${WRKSRC}/storage/build/Makefile.in \
		${WRKSRC}/db/sqlite3/src/Makefile.in
	${REINPLACE_CMD} -e 's|/usr/local/include|${LOCALBASE}/include|' \
	    	${WRKSRC}/js/src/config/mkdepend/Makefile.in
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g ; \
		s|echo aout|echo elf|g ; \
		s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/js/src/configure

pre-configure:
	(cd ${WRKSRC}/js/src/ && ${AUTOCONF})

post-build:
	@${REINPLACE_CMD} -e "s|\(Libs:.*\)\($$\)|\1 -Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}\2| ; \
	    	s|%sdkdir%|%sdkdir%/sdk|g ; \
		s|%%MOZ_LIBDIR%%|${PREFIX}/lib/${MOZILLA}|g" \
	    	${WRKSRC}/xulrunner/installer/*.pc.in || ${TRUE}

.include <bsd.port.post.mk>
