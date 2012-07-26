# New ports collection makefile for:	xulrunner
# Date created:		2006-02-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxul
DISTVERSION=	1.9.2.28
PORTREVISION=	1
CATEGORIES?=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	firefox/releases/3.6.28/source
DISTNAME=	firefox-3.6.28.source

MAINTAINER?=	gecko@FreeBSD.org
COMMENT?=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

WRKSRC=		${WRKDIR}/mozilla-1.9.2
CONFLICTS=	mozilla-[0-9]* libxul-[0-9][0-9].*
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/bin lib/${MOZILLA}/idl \
			lib/${MOZILLA}/include lib/${MOZILLA}/lib

USE_AUTOTOOLS=	autoconf213:env
WANT_GNOME=	yes
WANT_PERL=	yes
ALL_TARGET=	default
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	SKIP_GRE_REGISTRATION=1 mozappdir=${PREFIX}/lib/${MOZILLA}
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}
USE_LDCONFIG=	${PREFIX}/lib/${MOZILLA}

PORT_MOZCONFIG=	${WRKSRC}/xulrunner/config/mozconfig
MOZ_OPTIONS?=	--disable-ipc
MOZ_EXTENSIONS=	default,cookie,permissions
USE_GECKO=	gecko
MOZILLA_EXEC_NAME=xulrunner
USE_MOZILLA=	-event -ffi -vpx
MOZ_CHROME=	jar
MOZ_PKGCONFIG_FILES=	libxul-embedding libxul mozilla-gtkmozembed-embedding \
		mozilla-gtkmozembed mozilla-js mozilla-plugin

OPTIONS_DEFINE=	JAVA
JAVA_DESC?=	JAVA xpcom

.include "${.CURDIR}/../../www/firefox/Makefile.options"

OPTIONS_DEFINE:=${OPTIONS_DEFINE:NLIBPROXY}
OPTIONS_SINGLE:=${OPTIONS_SINGLE:NTOOLKIT}

.include <bsd.port.pre.mk>

.if ${USE_MOZILLA:M-nss}
MOZ_PKGCONFIG_FILES+=	mozilla-nss
.endif

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.elif ${ARCH} == powerpc64
.if ${OSVERSION} < 900033
BROKEN=		Needs binutils 2.17.50 to build
.else
MOZ_EXPORT+=	UNAME_m="powerpc64"
CFLAGS+=	-mminimal-toc
.endif
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_VERSION+=	1.5+
JAVA_OS+=	native
MOZ_EXPORT+=	JAVA_HOME="${JAVA_HOME}"
MOZ_OPTIONS+=	--enable-javaxpcom
.else
MOZ_OPTIONS+=	--disable-javaxpcom
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/include|${LOCALBASE}/include|' \
	    	${WRKSRC}/js/src/config/mkdepend/Makefile.in

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${WRKSRC}/js/src/ && ${AUTOCONF})

post-build:
	@${REINPLACE_CMD} -e "s|\(Libs:.*\)\($$\)|\1 -Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}\2| ; \
	    	s|%sdkdir%|%sdkdir%/sdk|g ; \
		s|%%MOZ_LIBDIR%%|${PREFIX}/lib/${MOZILLA}|g" \
	    	${WRKSRC}/xulrunner/installer/*.pc.in || ${TRUE}

.include <bsd.port.post.mk>
