# New ports collection makefile for:	ewl
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	ewl
PORTVERSION=	0.5.2.042
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightened Widget Library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	embryo edb evas edje ecore efreet
USE_EFL_ECORE=	txt file
WANT_EFL=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-tests

OPTIONS=	EPSILON	"Enable Epsilon Support for Ewl_Image" on \
		EMOTION "Enable Emotion Support for Ewl_Media" on \
		SOFTX11	"Enable software X11 evas engine support" on \
		XRENDER	"Enable XRender evas engine support" on \
		GL	"Enable OpenGL evas engine support" on \
		BUFFER	"Enable buffer evas engine support" on \
		SDL	"Enable SDL evas engine support" off

.include <bsd.port.pre.mk>

.if ${ARCH} == ia64
BROKEN=		does not compile on ${ARCH}
.endif

.if !defined(WITHOUT_EPSILON) || ${HAVE_EFL:Mepsilon}
USE_EFL+=	epsilon
.endif

.if !defined(WITHOUT_EMOTION) || ${HAVE_EFL:Memotion}
USE_EFL+=	emotion
.endif

.if !defined(WITHOUT_SOFTX11)
USE_EVAS_ENGINES+=	x11
CONFIGURE_ARGS+=	--enable-software-x11
PLIST_SUB+=		SOFTX11=""
WITH_ECORE_X=		yes
.else
CONFIGURE_ARGS+=	--disable-software-x11
PLIST_SUB+=		SOFTX11="@comment "
.endif

.if !defined(WITHOUT_XRENDER)
USE_EVAS_ENGINES+=	xrender
CONFIGURE_ARGS+=	--enable-xrender-x11
PLIST_SUB+=		XRENDER=""
WITH_ECORE_X=		yes
.else
CONFIGURE_ARGS+=	--disable-xrender-x11
PLIST_SUB+=		XRENDER="@comment "
.endif

.if !defined(WITHOUT_GL)
USE_EVAS_ENGINES+=	opengl
CONFIGURE_ARGS+=	--enable-opengl-x11
PLIST_SUB+=		GL=""
WITH_ECORE_X=		yes
.else
CONFIGURE_ARGS+=	--disable-opengl-x11
PLIST_SUB+=		GL="@comment "
.endif

.if defined(WITH_SDL)
CONFIGURE_ARGS+=	--enable-software-sdl
PLIST_SUB+=		SDL=""
USE_EFL_ECORE+=		sdl
.else
CONFIGURE_ARGS+=	--disable-software-sdl
PLIST_SUB+=		SDL="@comment "
.endif

.if defined(WITH_ECORE_X)
PLIST_SUB+=		X11=""
USE_EFL_ECORE+=		x11
.else
PLIST_SUB+=		X11="@comment "
.endif

.if !defined(WITHOUT_BUFFER)
USE_EVAS_ENGINES+=	buffer
CONFIGURE_ARGS+=	--enable-buffer
PLIST_SUB+=		BUFFER=""
.else
CONFIGURE_ARGS+=	--disable-buffer
PLIST_SUB+=		BUFFER="@comment "
.endif

.include <bsd.port.post.mk>
