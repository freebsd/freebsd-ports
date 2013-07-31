# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	mtr
PORTVERSION=	0.85
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traceroute and ping in a single network diagnostic tool

LICENSE=	GPLv2

OPTIONS_DEFINE=	GLIB IPV6 X11
OPTIONS_DEFAULT=X11
GLIB_DESC=	Build with glib library
X11_DESC=	Build X11-enabled mtr

GNU_CONFIGURE=	yes
USES=		pkgconfig

MAN8=		mtr.8
PLIST_FILES=	sbin/mtr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLIB}
CONFIGURE_ARGS+=--with-glib
USE_GNOME=	glib20
.else
CONFIGURE_ARGS+=--without-glib
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-ipv6
CATEGORIES+=	ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--with-gtk
USE_GNOME=	gtk20
.else
CONFIGURE_ARGS+=--without-gtk
PKGNAMESUFFIX+=	-nox11
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|getopt.*$$(OBJEXT)||g; s|getopt.*[ch]||g; /getopt.*Po/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|"getopt\.h"|<getopt.h>|g' ${WRKSRC}/mtr.c

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
