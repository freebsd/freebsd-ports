# New ports collection makefile for:   mtr
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	mtr
PORTVERSION=	0.73
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.mirrors.wiretapped.net/security/network-mapping/mtr/ \
		http://gd.tuwien.ac.at/infosys/network/tools/mtr/ \
		http://mirrors.evolva.ro/util/mtr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19 autoheader:262 autoconf:262

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
USE_XORG=	x11
CONFIGURE_ARGS+=--with-gtk-prefix=${LOCALBASE}
.else
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS=--without-gtk --with-gtk-prefix=/nonexistant
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e '/getopt/d' ${WRKSRC}/Makefile.am

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
