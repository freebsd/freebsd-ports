# New ports collection makefile for:   mtr
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	mtr
PORTVERSION=	0.54
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		ftp://ftp.netsw.org/net/ip/audit/packets/ \
		ftp://ftp.gw.com/mirrors/pub/unix/mtr/

MAINTAINER=	billf@FreeBSD.org
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
WANT_IPV6=	yes

MAN8=	mtr.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014 && defined(WANT_IPV6)
PATCHFILES=	mtr-054-v6-20040130.diff.gz
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCH_DIST_STRIP=	-p1

CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if !defined(WITHOUT_GNOME) && ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
USE_XLIB=	yes
.else
CONFIGURE_ARGS+=--without-gtk --with-gtk-prefix=/nonexistant
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4
	@${TOUCH} ${WRKSRC}/stamp-h.in
	@${TOUCH} ${WRKSRC}/img/Makefile.in

do-install:
	${INSTALL} -c -s -m 4755 -o root -g wheel ${WRKSRC}/mtr ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mtr.8 ${PREFIX}/man/man8

post-install:
	@${ECHO} ""
	@${ECHO} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO} ""
	@${ECHO} "Please read about potential security issues"
	@${ECHO} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO} ""

.include <bsd.port.post.mk>
