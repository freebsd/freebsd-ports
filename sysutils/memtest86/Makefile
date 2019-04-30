# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	memtest86
PORTVERSION=	4.3.7
CATEGORIES=	sysutils
MASTER_SITES=	https://www.memtest86.com/downloads/

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Stand alone memory test for x86 architecture computers

NO_WRKSUBDIR=	yes

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_MULTI=	IMAGE
OPTIONS_MULTI_IMAGE=	USB CD-ROM FLOPPY
OPTIONS_DEFAULT=	USB
OPTIONS_SUB=	yes

IMAGE_DESC=	Image selection

USB_DESC=	Image for creating bootable USB Drive
USB_DISTFILES=	${DISTNAME}-usb${EXTRACT_SUFX}

CD-ROM_DESC=	Image for creating bootable CD-ROM Drive
CD-ROM_DISTFILES=	${DISTNAME}-iso${EXTRACT_SUFX}

FLOPPY_DESC=	Image for creating bootable Floppy Drive
FLOPPY_DISTFILES=	${DISTNAME}-floppy${EXTRACT_SUFX}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

do-install-USB-on:
	${INSTALL_DATA} ${WRKSRC}/memtest86-usb.img ${STAGEDIR}${DATADIR}

do-install-CD-ROM-on:
	${INSTALL_DATA} ${WRKSRC}/Memtest86-4.3.7.iso ${STAGEDIR}${DATADIR}/memtest86-cdrom.iso

do-install-FLOPPY-on:
	${INSTALL_DATA} ${WRKSRC}/memtest86-floppy.img ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
