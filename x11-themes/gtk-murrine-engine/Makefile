# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	murrine
PORTVERSION=	0.98.1.1
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
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	ANIMATION
OPTIONS_DEFAULT=	ANIMATION
ANIMATION_DESC=	Animation support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANIMATION}
CONFIGURE_ARGS+=--enable-animation
.endif

.include <bsd.port.mk>
