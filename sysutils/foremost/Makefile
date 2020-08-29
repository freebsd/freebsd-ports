# Created by: Yonatan <Yonatan@xpert.com>
# $FreeBSD$

PORTNAME=	foremost
PORTVERSION=	1.5.7
CATEGORIES=	sysutils
MASTER_SITES=	http://foremost.sourceforge.net/pkg/

MAINTAINER=	onatan@gmail.com
COMMENT=	Console program to recover files based on their headers and footers

USES=		gmake
ALL_TARGET=	freebsd
CFLAGS+=	-fcommon

PLIST_FILES=	bin/foremost etc/foremost.conf.sample man/man8/foremost.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; s|-Wall -O2|${CFLAGS}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/config.c
	@${GZCAT} ${WRKSRC}/foremost.8.gz | ${SED} -e 's|/etc|${PREFIX}/etc|' \
	> ${WRKSRC}/foremost.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/foremost.conf ${STAGEDIR}${PREFIX}/etc/foremost.conf.sample
	${INSTALL_MAN} ${WRKSRC}/foremost.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
