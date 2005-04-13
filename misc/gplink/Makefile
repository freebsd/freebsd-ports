# New ports collection makefile for:	gplink
# Date created:				Sun Dec  5 23:17:44 CET 2004
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	gplink
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	http://dexy.mine.nu/gp32/gplink/

MAINTAINER=	king@v2project.com
COMMENT=	A GP32 USB linker tool

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	bin/gplink

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplink ${PREFIX}/bin

.include <bsd.port.mk>
