# Ports collection makefile for:  foremost
# Date created:			  16 June 2004
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	foremost
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/pkg/

MAINTAINER=	onatan@gmail.com
COMMENT=	Console program to recover files based on their headers and footers

USE_GMAKE=	yes
ALL_TARGET=	freebsd
MAN1=		foremost.1
USE_REINPLACE=	yes

PLIST_FILES=	bin/foremost etc/foremost.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-Wall -O2|${CFLAGS}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/config.c
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/${MAN1}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/foremost.conf ${PREFIX}/etc/foremost.conf.sample
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
