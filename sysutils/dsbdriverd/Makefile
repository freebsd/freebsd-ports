# Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbdriverd
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Hardware detecting, device driver loading daemon

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz

OPTIONS_DEFINE=	PCIIDS USBIDS

PCIIDS_DESC=	Use pci.ids database to show PCI device information
USBIDS_DESC=	Use usb.ids database to show USB device information

OPTIONS_DEFAULT=PCIIDS USBIDS

PCIIDS_RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids
USBIDS_RUN_DEPENDS=	${LOCALBASE}/share/usbids/usb.ids:misc/usbids

MAKE_ARGS+=	DBDIR=${DATADIR}
PCIIDS_MAKE_ARGS=	PCIDB0=${LOCALBASE}/share/pciids/pci.ids
USBIDS_MAKE_ARGS=	USBDB=${LOCALBASE}/share/usbids/usb.ids

PORTDATA=	drivers.db

USE_RC_SUBR=	dsbdriverd

PLIST_FILES=	libexec/dsbdriverd man/man8/dsbdriverd.8.gz

.include <bsd.port.mk>
