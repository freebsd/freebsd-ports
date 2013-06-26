# $FreeBSD$

PORTNAME=	xf86-video-mga
PORTVERSION=	1.6.2
PORTEPOCH=	3
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org mga display driver

USE_GL=		gl

XORG_CAT=	driver
USE_XORG=	xf86driproto glproto
MAN4=		mga.4x

pre-patch:
#	${REINPLACE_CMD} \
#		-e 's|values.h|sys/limits.h|g' \
#		-e 's|MAXSHORT|SHRT_MAX|g' \
#		${WRKSRC}/src/mga_arc.c

.include <bsd.port.mk>
