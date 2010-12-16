# New ports collection makefile for:    aespipe
# Date created:         20 February 1007
# Whom:			Ekkehard 'Ekki' Gehm <gehm@physik.tu-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	aespipe
DISTVERSION=	v2.3e
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://loop-aes.sourceforge.net/${PORTNAME}/ \
		http://koti.tnnet.fi/jari.ruusu/linux/

MAINTAINER=	gehm@physik.tu-berlin.de
COMMENT=	An AES encrypting or decrypting pipe

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

MAN1=		aespipe.1

USE_BZIP2=	yes

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/aespipe

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
.include <bsd.port.post.mk>
