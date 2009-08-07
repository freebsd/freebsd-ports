# New ports collection makefile for:	xulrunner
# Date created:		2006-02-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/libxul/Makefile,v 1.25 2009/04/07 17:47:01 marcus Exp $
#

PORTNAME=	libxul
PORTVERSION=	1.9.0.13
CATEGORIES?=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	xulrunner/releases/${PORTVERSION}/source/
DISTNAME=	xulrunner-${PORTVERSION}-source

MAINTAINER?=	gecko@FreeBSD.org
COMMENT?=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

LIB_DEPENDS?=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

CONFLICTS=	mozilla-[0-9]* xulrunner-[0-9]*
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/bin lib/${MOZILLA}/idl \
			lib/${MOZILLA}/include lib/${MOZILLA}/lib \
			lib/${MOZILLA}/sdk/idl lib/${MOZILLA}/sdk/include

WANT_GNOME=	yes
WANT_PERL=	yes
ALL_TARGET=	default
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	SKIP_GRE_REGISTRATION=1 mozappdir=${PREFIX}/lib/${MOZILLA}
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}

PORT_MOZCONFIG=	${WRKSRC}/xulrunner/config/mozconfig
MOZ_OPTIONS?=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--disable-javaxpcom --enable-canvas \
		--enable-system-cairo
MOZ_EXTENSIONS=	default,cookie,permissions
OPTIONS=	# Empty, used for generic gecko OPTIONS
USE_GECKO_OPTIONS=	java debug logging optimized_cflags
USE_GECKO=	gecko
MOZILLA_EXEC_NAME=xulrunner
MOZ_TOOLKIT=	cairo-gtk2
USE_MOZILLA=	-png -nss -dbm -jpeg
MOZ_PKGCONFIG_FILES=	libxul-embedding-unstable libxul-embedding \
		libxul-unstable	libxul mozilla-gtkmozembed-embedding \
		mozilla-gtkmozembed mozilla-js mozilla-nss mozilla-plugin

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:C/-pthread/${GECKO_PTHREAD_LIBS}/}|' \
	    	${WRKSRC}/storage/build/Makefile.in \
		${WRKSRC}/db/sqlite3/src/Makefile.in

post-build:
	@${REINPLACE_CMD} -e "s|\(Libs:.*\)\($$\)|\1 -Wl,-rpath,${PREFIX}/lib/${MOZ_RPATH}\2| ; \
	    	s|%sdkdir%|%sdkdir%/sdk|g ; \
		s|%%MOZ_LIBDIR%%|${PREFIX}/lib/${MOZILLA}|g" \
	    	${WRKSRC}/xulrunner/installer/*.pc.in || ${TRUE}

.include <bsd.port.post.mk>
