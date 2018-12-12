# Created by: Dmitry N Fomin <fdn@okbire.ru>
# $FreeBSD$

PORTNAME=	gdisk
PORTVERSION=	1.0.4
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/gptfdisk/gptfdisk/${PORTVERSION}
DISTNAME=	gptfdisk-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GPT fdisk

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libpopt.so:devel/popt \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		localbase:ldflags

ALL_TARGET=	fixparts gdisk sgdisk
MAKEFILE=	Makefile.freebsd

OPTIONS_DEFINE=	CGDISK UTF16
OPTIONS_SUB=	yes
CGDISK_DESC=	Curses-based interactive program
UTF16_DESC=	Support for Unicode partition names

CGDISK_ALL_TARGET=	cgdisk
CGDISK_USES=		ncurses
UTF16_USES=		compiler:c++11-lib
UTF16_CPPFLAGS=		-DUSE_UTF16
UTF16_CXXFLAGS=		-std=gnu++11
UTF16_LDFLAGS=		-licuio -licuuc
UTF16_LIB_DEPENDS=	libicuuc.so:devel/icu

do-install:
.for i in fixparts gdisk sgdisk
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${i}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.endfor

do-install-CGDISK-on:
	${INSTALL_PROGRAM} ${WRKSRC}/cgdisk ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/cgdisk.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
