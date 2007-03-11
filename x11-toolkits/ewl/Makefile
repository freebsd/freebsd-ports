# New ports collection makefile for:	ewl
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	ewl
PORTVERSION=	20070223
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightened Widget Library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	embryo edb evas edje ecore
WANT_EFL=	yes
USE_LDCONFIG=	yes

OPTIONS=	EPSILON	"Enable Epsilon Support for Ewl_Image" on \
		EMOTION "Enable Emotion Support for Ewl_Media" on

.include <bsd.port.pre.mk>
BEFOREPORTMK=	yes
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.undef BEFOREPORTMK

.if ${ARCH} == ia64
BROKEN=		does not compile on ${ARCH}
.endif

.if !defined(WITHOUT_EPSILON) || ${HAVE_EFL:Mepsilon}
USE_EFL+=	epsilon
PLIST_SUB+=	EPSILON=""
.else
PLIST_SUB+=	EPSILON="@comment "
.endif

.if !defined(WITHOUT_EMOTION) || ${HAVE_EFL:Memotion}
USE_EFL+=	emotion
PLIST_SUB+=	EMOTION=""
.else
PLIST_SUB+=	EMOTION="@comment "
.endif

.if exists(${LOCALBASE}/include/Evas_Engine_GL_X11.h)
PLIST_SUB+=	EVAS_GL=""
.else
PLIST_SUB+=	EVAS_GL="@comment "
.endif

.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
