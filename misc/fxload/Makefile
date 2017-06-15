# Created by: Wojciech A. Koszek <wkoszek@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fxload
PORTVERSION=	20140224
CATEGORIES=	misc
MASTER_SITES=	https://bitbucket.org/DJOConnor/fxload/get/
DISTNAME=	RELEASE_${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Firmware download for Cypress EZ-USB devices

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/DJOConnor-fxload-5691a2bb9409

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fxload ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/fxload.8 ${STAGEDIR}${PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/a3load.hex ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/xilinx.conf ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
