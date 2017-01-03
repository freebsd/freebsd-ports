# Created by: Guerkan Karaman <gk.freebsd@googlemail.com>
# $FreeBSD$

PORTNAME=	gpxe
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://etherboot.org/rel/gpxe/ \
		http://slackware.cs.utah.edu/pub/kernel.org/pub/software/utils/boot/gpxe/

MAINTAINER=	gk.freebsd@googlemail.com
COMMENT=	Open Source (GPL) gPXE network bootloader

LICENSE=	GPLv2

BROKEN=	does not build on FreeBSD 10.x and later
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2017-01-15

BUILD_DEPENDS=	syslinux:sysutils/syslinux \
		mkisofs:sysutils/cdrtools

USES=		gmake perl5
MAKE_ARGS=	PERL=${PERL}
WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	%%DATADIR%%/gpxe.dsk \
		%%DATADIR%%/gpxe.usb \
		%%DATADIR%%/gpxe.iso

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64/i386

.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=i386
.endif

ISOLINUX_BIN?=	${LOCALBASE}/share/syslinux/bios/core/isolinux.bin

post-patch:
	@${REINPLACE_CMD} "s|%%WRKSRC%%|${WRKSRC}|" ${WRKSRC}/arch/i386/Makefile

pre-build:
# ISO creation fails if isolinux.bin is read only
	${INSTALL} -m 644 ${ISOLINUX_BIN} ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/src/bin/gpxe.dsk ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/src/bin/gpxe.usb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/src/bin/gpxe.iso ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
