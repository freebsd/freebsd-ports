# New ports collection makefile for:	papaya
# Date created:		23 August 2001
# Whom:			Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	papaya
PORTVERSION=	0.96
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.gtk-papaya.org/downloads/source/
DISTNAME=	papaya-src-${PORTVERSION}

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	Graphical GTK mud client with plugin support

BUILD_DEPENDS=	${LOCALBASE}/include/pygtk-2.0/pygtk/pygtk.h:${PORTSDIR}/x11-toolkits/py-gtk2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
WANT_GNOME=	yes
USE_AUTOCONF=	yes
USE_PERL5_BUILD=yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomeprefix gnomehack gnomelibs
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

CONFIGURE_ENV+=	GLIBCONFIG=${GLIB_CONFIG} GTKCONFIG=${GTK_CONFIG}
CONFIGURE_ARGS=	--with-interface=gtk2 --enable-plugins=no
MAKE_ARGS+=	PTHREAD_LIBS=${PTHREAD_LIBS} CXX="${CXX}"

.include <bsd.port.post.mk>
