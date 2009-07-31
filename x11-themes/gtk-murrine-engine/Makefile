# New ports collection makefile for:	gtk-murrine-engine
# Date created:		2006-08-20
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	murrine
PORTVERSION=	0.90.3
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrine GTK+ 2.x cairo based engine

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS=	ANIMATION "Enable animation support" off

.include <bsd.port.pre.mk>

.if defined(WITH_ANIMATION)
CONFIGURE_ARGS+=--enable-animation
.endif

.include <bsd.port.post.mk>
