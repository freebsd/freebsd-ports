# $FreeBSD$

PORTNAME=	ftdi-eeprom
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.bwct.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to program the eeprom on FTDI usb devices

MAKE_ARGS=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/man/man"

PLIST_FILES=	sbin/ftdi-eeprom
MAN8=		ftdi-eeprom.8
MANCOMPRESSED=	maybe

NO_STAGE=	yes
.include <bsd.port.mk>
