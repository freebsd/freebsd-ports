# New ports collection makefile for:   gtk12
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	1.2.10
PORTREVISION=	10
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gtk+/1.2
DISTNAME=	gtk+-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (previous stable version)

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-suffix
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/gtk12 --with-native-locale \
		--with-xinput=xfree
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		X_CFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gtk-config.1

pre-build:
	${RM} -rf ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${PREFIX}/lib/gtk/themes/engines
	@${LN} -sf ${PREFIX}/bin/gtk-config ${PREFIX}/bin/gtk12-config

.include <bsd.port.mk>
