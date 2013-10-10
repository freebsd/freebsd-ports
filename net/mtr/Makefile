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

PLIST_FILES=	man/man8/mtr.8.gz \
		sbin/mtr

GLIB_CONFIGURE_WITH=	glib
GLIB_USE=		GNOME=glib20
IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_ENABLE=	ipv6
X11_CONFIGURE_WITH=	gtk
X11_USE=		GNOME=gtk20

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MX11}
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
