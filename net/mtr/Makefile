# New ports collection makefile for:   mtr
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	mtr
PORTVERSION=	0.71
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.mirrors.wiretapped.net/security/network-mapping/mtr/ \
		http://gd.tuwien.ac.at/infosys/network/tools/mtr/ \
		http://mirrors.evolva.ro/util/mtr/

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN8=		mtr.8
PLIST_FILES=	sbin/mtr

.if !defined(WITHOUT_X11)
.if defined(WITH_GTK1)
USE_GNOME=	gtk12
PKGNAMESUFFIX=	-gtk1
.else
USE_GNOME=	gtk20
CONFIGURE_ARGS=--enable-gtk2
.endif
USE_XLIB=	yes
CONFIGURE_ARGS+=--with-gtk-prefix=${X11BASE}
.else
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS=--without-gtk --with-gtk-prefix=/nonexistant
.endif

post-install:
	@${ECHO} ""
	@${ECHO} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO} ""
	@${ECHO} "Please read about potential security issues"
	@${ECHO} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO} ""

.include <bsd.port.mk>
