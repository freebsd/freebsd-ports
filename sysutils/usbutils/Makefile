# New ports collection makefile for:	usbutils
# Date created:		14 Nov 2007
# Whom:			Henrik Brix Andersen <brix@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	usbutils
PORTVERSION=	0.86
CATEGORIES=	sysutils
MASTER_SITES=	SF/linux-usb/${PORTNAME}

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Utility for listing USB devices

LICENSE=	GPLv2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--datadir=${DATADIR} --enable-zlib
USE_GMAKE=	yes
USE_GNOME=	pkgconfig

MAN1=		usb-devices.1
MAN8=		lsusb.8
PORTDOCS=	AUTHORS ChangeLog NEWS README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.else
CONFIGURE_ENV+=	LIBUSB_CFLAGS="-I/usr/include" \
		LIBUSB_LIBS="-L/usr/lib -lusb"
.endif

post-patch:
	@${REINPLACE_CMD} -i '' \
		-e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/usb-devices

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
