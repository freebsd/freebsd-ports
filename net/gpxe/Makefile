# Created by: Guerkan Karaman <gk.freebsd@googlemail.com>
# $FreeBSD$

PORTNAME=	gpxe
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://etherboot.org/rel/gpxe/ \
		http://slackware.cs.utah.edu/pub/kernel.org/pub/software/utils/boot/gpxe/

MAINTAINER=	gk.freebsd@googlemail.com
COMMENT=	Create an open-source PXE implementation and bootloader

LICENSE=	GPLv2

BUILD_DEPENDS=	syslinux:${PORTSDIR}/sysutils/syslinux

USE_CDRTOOLS=	yes
USES=		gmake perl5
WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_DIRS=	%%DATADIR%%
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

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/arch/i386/Makefile

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/src/bin/gpxe.dsk ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/src/bin/gpxe.usb ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/src/bin/gpxe.iso ${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
