PORTNAME=	usbids
PORTVERSION=	20240704
CATEGORIES=	misc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database of all known IDs used in USB devices
WWW=		http://www.linux-usb.org/

LICENSE=	BSD3CLAUSE GPLv2+
LICENSE_COMB=	dual

NO_ARCH=	yes
NO_BUILD=	yes

PORTDATA=	usb.ids

USE_GITHUB=	yes
GH_TAGNAME=	e3a144a

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/usb.ids ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
