# $FreeBSD$

PORTNAME=	xf86-video-ati
PORTVERSION=	${ATI_VERSION}
PORTREVISION=	${ATI_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org ati display driver

USE_GL=		gl
XORG_CAT=	driver
USE_XORG=	xf86driproto xineramaproto xf86miscproto glproto

.include <bsd.port.options.mk>

.if (${OSVERSION} >= 902508 && ${OSVERSION} < 1000000) || ${OSVERSION} >= 1000051
#  902508: Radeon kernel driver imported in FreeBSD 9.x
# 1000051: Radeon kernel driver imported in FreeBSD 10.x
. if defined(WITH_NEW_XORG)
NEW_ATI_DRIVER=	yes
. else
NEW_ATI_DRIVER=	no
. endif
.else
# FreeBSD < 902508 doesn't have the Radeon kernel driver. No need to
# check for WITH_NEW_XORG. But we do support a flag to force the usage
# of the KMS-only DDX: this is used by the build cluster only.
. if defined(FORCE_KMS_ONLY_DDX)
NEW_ATI_DRIVER=	yes
. else
NEW_ATI_DRIVER=	no
. endif
.endif

.if (${ARCH} != i386 && ${ARCH} != amd64)
# No Radeon kernel driver on non-x86 and PC98.
NEW_ATI_DRIVER=	no
.endif

.if ${NEW_ATI_DRIVER} == no
ATI_VERSION=	6.14.6
ATI_REVISION=	4
CONFIGURE_ARGS+=--disable-kms
PLIST_SUB+=	OLD=""
.else
ATI_VERSION=	7.2.0
ATI_REVISION=	4
CONFIGURE_ARGS+=--disable-udev
CONFIGURE_ARGS+=--disable-glamor
EXTRA_PATCHES+=	${FILESDIR}/extra-src__radeon_kms.c
PLIST_SUB+=	OLD="@comment "
.endif

.include <bsd.port.mk>
