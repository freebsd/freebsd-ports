# New ports collection makefile for:	ftdi-eeprom
# Date created:		2003-02-15
# Whom:			Christian Weisgerber <naddy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ftdi-eeprom
PORTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.bwct.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to programm the eeprom on FTDI usb devices

MAKE_ARGS=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/man/man"

PLIST_FILES=	sbin/ftdi-eeprom
MAN8=		ftdi-eeprom.8
MANCOMPRESSED=	maybe

.include <bsd.port.mk>
