# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	mtr
PORTVERSION=	0.93
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traceroute and ping in a single network diagnostic tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf ncurses pkgconfig

GNU_CONFIGURE=	yes
LDFLAGS+=	-lncurses

GH_ACCOUNT=	traviscross
USE_GITHUB=	yes

CONFLICTS_INSTALL?=	mtr-nox11

OPTIONS_DEFINE=	IPV6 X11
OPTIONS_DEFAULT=X11
X11_DESC=	Build X11-enabled mtr

IPV6_CONFIGURE_ENABLE=	ipv6
X11_CONFIGURE_WITH=	gtk
X11_USE=		GNOME=gtk20
X11_USES=		gnome

post-patch:
	@${REINPLACE_CMD} -e 's|m4_esyscmd(\[build-aux/git-version-gen \.tarball-version\])|${PORTVERSION}|' ${WRKSRC}/configure.ac

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PREFIX}/sbin/mtr is setuid \"root\" "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please read about potential security issues"
	@${ECHO_MSG} "in file ${WRKSRC}/SECURITY (not installed)"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
