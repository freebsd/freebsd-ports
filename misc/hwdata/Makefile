# Created by: Ting-Wei Lan <lantw44@gmail.com>
# $FreeBSD$

PORTNAME=	hwdata
DISTVERSIONPREFIX=	v
DISTVERSION=	0.345
PORTEPOCH=	1
CATEGORIES=	misc

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Database of IDs used in PCI, PNP and USB devices

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	vcrhonek

NO_ARCH=	yes
NO_BUILD=	yes

_ID_FILES=	pci.ids pnp.ids usb.ids
PLIST_FILES=	${_ID_FILES:C,^,${DATADIR}/,}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
.for _id_file in ${_ID_FILES}
	${INSTALL_DATA} ${WRKSRC}/${_id_file} ${STAGEDIR}${DATADIR}/
.endfor

.include <bsd.port.mk>
