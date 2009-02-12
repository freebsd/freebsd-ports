# Ports collection makefile for:  foremost
# Date created:			  16 June 2004
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	foremost
PORTVERSION=	1.5.5
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	onatan@gmail.com
COMMENT=	Console program to recover files based on their headers and footers

USE_GMAKE=	yes
ALL_TARGET=	freebsd
MAN8=		foremost.8

PLIST_FILES=	bin/foremost etc/foremost.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-Wall -O2|${CFLAGS}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/config.c
	@${GZCAT} ${WRKSRC}/${MAN8}.gz | ${SED} -e 's|/etc|${PREFIX}/etc|' \
	> ${WRKSRC}/${MAN8}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/foremost.conf ${PREFIX}/etc/foremost.conf.sample
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
