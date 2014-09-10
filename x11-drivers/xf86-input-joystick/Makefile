# $FreeBSD$

PORTNAME=	xf86-input-joystick
PORTVERSION=	${JOYVER}
PORTREVISION=	1
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org joystick input driver

XORG_CAT=	driver

.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
JOYVER=		1.6.2
JOYREVISION=	1
.else
JOYVER=		1.5.0
JOYREVISION=	2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
