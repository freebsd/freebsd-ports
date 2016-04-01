# Created by: Ekkehard 'Ekki' Gehm <gehm@physik.tu-berlin.de>
# $FreeBSD$

PORTNAME=	aespipe
DISTVERSION=	v2.4c
CATEGORIES=	security
MASTER_SITES=	http://loop-aes.sourceforge.net/${PORTNAME}/ \
		http://koti.tnnet.fi/jari.ruusu/linux/

MAINTAINER=	gehm@physik.tu-berlin.de
COMMENT=	AES encrypting or decrypting pipe

LICENSE=	GPLv2

RUN_DEPENDS=	gpg:security/gnupg

USES=	tar:bzip2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/aespipe man/man1/aespipe.1.gz

.include <bsd.port.pre.mk>

ALL_TARGET=
.if ${ARCH} == amd64
MAKE_ARGS=	amd64
.endif

.if ${ARCH} == i386
MAKE_ARGS=	x86
.endif

post-build:
	cd ${WRKSRC} && make tests

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
