# ex:ts=8
# New ports collection makefile for:	libdvdcss
# Date created:		Jul 6, 2001
# Whom:			ijliao
#
# $FreeBSD$
#

PORTNAME=	libdvdcss
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.videolan.org/pub/videolan/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt \
		mad:${PORTSDIR}/audio/mad \
		SDL-1.1:${PORTSDIR}/devel/sdl12

USE_XLIB=	yes
WANT_ESOUND=	yes
WANT_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-release
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's|(LIBDVDCSS_VERSION=)"[\d\.]+?\.(\d)"|\1"\2"|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${PERL} -pi -e 's|^.+?ln.+?FULL_SO.+?MAJOR_SO.+\n||' \
		${WRKSRC}/extras/libdvdcss/Makefile

.include <bsd.port.pre.mk>

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
CONFIGURE_ARGS+=	--enable-esd
.endif

.if defined(HAVE_GTK)
USE_GTK=	yes
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.include <bsd.port.post.mk>
