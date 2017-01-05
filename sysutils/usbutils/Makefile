# Created by: Henrik Brix Andersen <brix@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbutils
PORTVERSION=	0.86
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/linux-usb/${PORTNAME} \
		http://pkgs.fedoraproject.org/repo/pkgs/usbutils/usbutils-0.86.tar.gz/34979f675d2bcb3e1b45012fa830a53f/ \
		http://ftp.be.debian.org/pub/linux/utils/usb/usbutils/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for listing USB devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datadir=${DATADIR} --enable-zlib

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/PKG_CONFIG.*libusb/s/ >= 0\.1\.[0-9]*/-0.1/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -i '' \
		-e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/usb-devices

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
