# New ports collection Makefile for:	gpxe
# Date created:				27-02-2010
# Whom:					Guerkan Karaman <gk.freebsd@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	gpxe
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=software/utils/boot/gpxe

MAINTAINER=	gk.freebsd@googlemail.com
COMMENT=	Create an open-source PXE implementation and bootloader

LICENSE=	GPLv2

BUILD_DEPENDS=	syslinux:${PORTSDIR}/sysutils/syslinux

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_CDRTOOLS=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_JOBS_SAFE=	yes

PLIST_DIRS=	%%DATADIR%%
PLIST_FILES=	%%DATADIR%%/gpxe.dsk \
		%%DATADIR%%/gpxe.usb \
		%%DATADIR%%/gpxe.iso

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
