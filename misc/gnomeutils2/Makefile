# New ports collection makefile for:	gnomeutils
# Date created:				03 July 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnomeutils
PORTVERSION=	1.4.1.2
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-utils
DISTNAME=	gnome-utils-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	msgfmt-new:${PORTSDIR}/devel/gettext-devel
LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-messages=/var/log/messages
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		MSGFMT=${LOCALBASE}/bin/msgfmt-new \
		XGETTEXT=${LOCALBASE}/bin/xgettext-new
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=	gcalc.1 gcharmap.1 gcolorsel.1 gdialog.1 gdict.1 gdiskfree.1 \
	gfontsel.1 gless.1 gnome-exe-handler.1 gsearchtool.1 guname.1 gw.1 \
	gtt.1 logview.1 meat-grinder.1 splac.1 splash.1 stripchart-applet.1 \
	stripchart.1
MAN8=	gshutdown.8

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
