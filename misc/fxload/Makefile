# Created by: Wojciech A. Koszek <wkoszek@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fxload
PORTVERSION=	20100510
CATEGORIES=	misc
MASTER_SITES=	http://FreeBSD.czest.pl/~wkoszek/ports/

MAINTAINER=	uffe@uffe.org
COMMENT=	Firmware download to EZ-USB devices

USES=		gmake
SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fxload ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/fxload.8 ${STAGEDIR}${PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${WRKSRC}/a3load.hex ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/xilinx.conf ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 800069)
BROKEN=	doesn't build on FreeBSD prior libusb(8) integration to base system
.endif

.include <bsd.port.post.mk>
