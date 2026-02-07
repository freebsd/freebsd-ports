PORTNAME=	ftdi-eeprom
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.bwct.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to program the eeprom on FTDI usb devices
WWW=		https://www.bwct.de/

MAKE_ARGS=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/share/man/man"

PLIST_FILES=	sbin/ftdi-eeprom share/man/man8/ftdi-eeprom.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftdi-eeprom ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ftdi-eeprom.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
