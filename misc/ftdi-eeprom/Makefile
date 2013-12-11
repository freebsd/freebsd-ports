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

PLIST_FILES=	sbin/ftdi-eeprom man/man8/ftdi-eeprom.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftdi-eeprom ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ftdi-eeprom.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
