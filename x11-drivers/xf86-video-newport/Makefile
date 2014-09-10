# $FreeBSD$

PORTNAME=	xf86-video-newport
PORTVERSION=	0.2.4
PORTREVISION=	4
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org newport display driver

XORG_CAT=	driver

post-patch:
		${REINPLACE_CMD} -e 's|values.h|sys/limits.h|' \
				 -e 's|MAXSHORT|SHRT_MAX|g' \
				 ${WRKSRC}/src/newport_accel.c

.include <bsd.port.mk>
