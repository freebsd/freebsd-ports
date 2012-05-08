# New ports collection makefile for:   libXaw
# Date Created:			25 Jan, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXaw
PORTVERSION=	1.0.9
PORTEPOCH=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Athena Widgets library

XORG_CAT=	lib
USE_XORG=	printproto:both x11 xau xext xextproto xmu xp xpm xproto:both xt
USE_GMAKE=	yes
CONFIGURE_ARGS=	--without-xmlto

PORTDOCS=	*

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=--disable-specs
post-configure:
	@${REINPLACE_CMD} -e '/AM_MAKEFLAGS/s/ install-exec-am install-data-am/ install-exec-am/' ${WRKSRC}/specs/Makefile
.endif

MAN3=		Xaw.3

.include <bsd.port.mk>
