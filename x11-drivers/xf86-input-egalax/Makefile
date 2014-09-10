# Created by: Gleb Smirnoff <glebius@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xf86-input-egalax
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	x11-drivers
MASTER_SITES=	LOCAL/glebius

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	eGalax touch screen input driver for X.Org

LICENSE=	BSD2CLAUSE

XORG_CAT=	driver
INSTALL_CMD=	install-strip

.include <bsd.port.pre.mk>

.if defined(WITH_NEW_XORG)
IGNORE=		does not build with X server 1.12
.endif

.include <bsd.port.post.mk>
