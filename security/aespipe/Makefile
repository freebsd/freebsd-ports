# Created by: Ekkehard 'Ekki' Gehm <gehm@physik.tu-berlin.de>
# $FreeBSD$

PORTNAME=	aespipe
PORTVERSION=	2.4d
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	http://loop-aes.sourceforge.net/${PORTNAME}/ \
		http://koti.tnnet.fi/jari.ruusu/linux/

MAINTAINER=	gehm@physik.tu-berlin.de
COMMENT=	AES encrypting or decrypting pipe

LICENSE=	GPLv2

RUN_DEPENDS=	gpg:security/gnupg

USES=		tar:bzip2

GNU_CONFIGURE=	yes
TEST_TARGET=	tests

PLIST_FILES=	bin/aespipe man/man1/aespipe.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
