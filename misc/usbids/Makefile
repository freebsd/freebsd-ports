PORTNAME=	usbids
PORTVERSION=	20231108
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
GH_TAGNAME=	6c41b72

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/usb.ids ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
