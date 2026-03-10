PORTNAME=	usb_modeswitch
DISTVERSION=	2.6.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.draisberghof.de/usb_modeswitch/
DISTNAME=	${PORTNAME:S|_|-|}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DATANAME}${EXTRACT_SUFX}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Handling Mode-Switching USB Devices
WWW=		https://www.draisberghof.de/usb_modeswitch/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bzip2

DATAVERSION=	20251207
DATANAME=	${PORTNAME:S|_|-|}-data-${DATAVERSION}

pre-patch:
	${REINPLACE_CMD} 's|`pkg-config --libs --cflags libusb-1.0`|-lusb|; \
			  s|gcc|${CC}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usb_modeswitch ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/usb_modeswitch.conf \
		${STAGEDIR}${PREFIX}/etc/usb_modeswitch.conf.sample
	${INSTALL_MAN} ${WRKSRC}/usb_modeswitch.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	cd ${WRKDIR}/${DATANAME}/usb_modeswitch.d && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
