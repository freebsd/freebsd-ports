# New ports collection makefile for:   mtr
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	mtr
PORTVERSION=	0.81
PORTREVISION?=	0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://launchpadlibrarian.net/82181604/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

OPTIONS=	IPV6	"Build IPv6 support" on \
		X11	"Build X11-enabled mtr" on

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN8=		mtr.8
PLIST_FILES=	sbin/mtr

.include <bsd.port.options.mk>

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
CATEGORIES+=	ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if !defined(WITHOUT_X11)
CONFIGURE_ARGS+=--with-gtk
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=--without-gtk
PKGNAMESUFFIX=	-nox11
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|getopt.*$$(OBJEXT)||g; s|getopt.*[ch]||g; /getopt.*Po/d' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"getopt\.h"|<getopt.h>|g' ${WRKSRC}/mtr.c

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
