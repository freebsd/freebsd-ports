# New ports collection makefile for:	balsa
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	balsa
PORTVERSION= 	0.9.5
CATEGORIES=	mail gnome
MASTER_SITES=	ftp://ftp.newton.cx/pub/balsa/ \
		http://www.theochem.kth.se/~pawsa/balsa/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		PropList.2:${PORTSDIR}/devel/libPropList \
		pspell.2:${PORTSDIR}/textproc/pspell \
		gnomeprint.9:${PORTSDIR}/print/gnomeprint
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter \
		${X11BASE}/share/gnome/sounds/login.wav:${PORTSDIR}/audio/gnomeaudio \
		panel:${PORTSDIR}/x11/gnomecore

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libmutt/configure
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		GTK_CONFIG='${GTK_CONFIG}' \
		GLIB_CONFIG='${GLIB_CONFIG}' \
		LIBS='-L${LOCALBASE}/lib'
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX} \
		--enable-threads \
		--disable-more-warnings

MAN1=		balsa.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|\$\(gnomedatadir\)/gnome|\$\(gnomedatadir\)|g'

.include <bsd.port.mk>
