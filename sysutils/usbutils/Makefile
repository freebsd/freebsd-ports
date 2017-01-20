# Created by: Henrik Brix Andersen <brix@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbutils
PORTVERSION=	0.91
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility for listing USB devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	usbhid-dump:sysutils/usbhid-dump \
		${LOCALBASE}/share/usbids/usb.ids:misc/usbids

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--datadir=${LOCALBASE}/share/usbids --enable-zlib
CONFIGURE_ENV=	LIBUSB_CFLAGS="-I/usr/include" LIBUSB_LIBS="-L/usr/lib -lusb"
GNU_CONFIGURE=	yes
USES=		autoreconf gmake pkgconfig shebangfix

PORTDOCS=	AUTHORS ChangeLog NEWS README

GH_ACCOUNT=	gregkh
USE_GITHUB=	yes

SHEBANG_FILES=	usb-devices

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
