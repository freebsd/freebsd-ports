# New ports collection makefile for:   fxload
# Date created:		10 May 2010
# Whom:			Wojciech A. Koszek <wkoszek@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fxload
PORTVERSION=	20100510
CATEGORIES=	misc
MASTER_SITES=	http://FreeBSD.czest.pl/~wkoszek/ports/

MAINTAINER=	wkoszek@FreeBSD.org
COMMENT=	Firmware download to EZ-USB devices

MAN8=		fxload.8
USE_GMAKE=	yes
SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fxload ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/fxload.8 ${PREFIX}/man/man8
	${MKDIR} ${DATADIR}
	${MKDIR} ${PREFIX}/etc/devd
	${INSTALL_DATA} ${WRKSRC}/a3load.hex ${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/xilinx.conf ${PREFIX}/etc/devd

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 800069)
BROKEN=	doesn't build on FreeBSD prior libusb(8) integration to base system
.endif

.include <bsd.port.post.mk>
