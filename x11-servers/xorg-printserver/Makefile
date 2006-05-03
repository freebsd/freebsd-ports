# New ports collection makefile for:    xorg-printserver
# Date created:		17 June 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-printserver
PORTVERSION=	6.9.0
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R${PORTVERSION}/src
DISTFILES=	X11R${PORTVERSION}-src1.tar.gz \
		X11R${PORTVERSION}-src3.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Print server from X.Org

CONFLICTS=	XFree86-PrintServer-*

EXTRA_PATCHES=	${CF_PATCHES} ${SERVER_PATCHES}

USE_XLIB=	yes

XBUILD_DIRS=	lib/font programs/Xserver
XINCLUDE_DIRS=	lib/xtrans
XMAN_DIRS=	programs/Xserver

# Ensure that we pick up imake's makedepend instead of devel/makedepend
MAKE_ENV+=	PATH=${X11BASE}/bin:${PATH}

MAN1=		Xprt.1

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org and you have ${X_WINDOW_SYSTEM} set for X11\
	distribution. See The X Window System and Virtual Consoles chapter\
	of FAQ for more information
.endif
.include <bsd.port.post.mk>
