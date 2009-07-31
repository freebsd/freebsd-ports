# New ports collection makefile for:   mtr
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	mtr
PORTVERSION=	0.75
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://gd.tuwien.ac.at/infosys/network/tools/mtr/ \
		http://mirrors.evolva.ro/util/mtr/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN8=		mtr.8
PLIST_FILES=	sbin/mtr

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=--without-gtk
.else
USE_GNOME=	gtk20
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|getopt.*$$(OBJEXT)||g ; \
		 s|getopt.*[ch]||g ; \
		 /getopt.*Po/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"getopt\.h"|<getopt.h>|g' ${WRKSRC}/mtr.c
.if ${OSVERSION} < 700024
	@${REINPLACE_CMD} -e \
		's|-Wno-pointer-sign||' ${WRKSRC}/configure
.endif

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
