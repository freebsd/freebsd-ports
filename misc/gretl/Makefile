# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	0.999
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Gnu Regression, Econometrics and Time-series Library

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	gnomeole2.0:${PORTSDIR}/devel/libole2 \
		gmp.6:${PORTSDIR}/math/libgmp4 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gdkpixbuf
WANT_GNOME=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gmake --without-gtk2
INSTALLS_SHLIB=	yes

MAN1=	gretl.1 gretl-config.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomeprint}!= ""
USE_GNOME+=	gnomeprint gnomeprefix
PKGNAMESUFFIX=  -gnome
.else
CONFIGURE_ARGS+=	--without-gnome
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|`glib-config|`\$$GLIB_CONFIG|g ; \
		 s|/share/gretl/|/lib/gretl/|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|SIGCLD|SIGCHLD|g' ${WRKSRC}/gui/gretl.c

.include <bsd.port.post.mk>
