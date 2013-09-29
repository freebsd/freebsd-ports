# Created by: lesi@FreeBSD.org
# $FreeBSD$

PORTNAME=	xf86-video-intel
PORTVERSION=	${INTEL_VERSION}
PORTREVISION=	${INTEL_REVISION}
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Driver for Intel integrated graphics chipsets

ONLY_FOR_ARCHS=	amd64 i386
USE_GL=		gl

USE_LDCONFIG=	yes
XORG_CAT=	driver
USE_XORG=	glproto \
		pixman \
		x11 \
		xext \
		xf86driproto \
		xineramaproto \
		xrender \
		xvmc

MAN4=		intel.4x

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if defined(WITH_NEW_XORG)
INTEL_VERSION=	2.21.15
INTEL_REVISION=	0
CONFIGURE_ENV+=	xorg_cv_cc_flag__Wno_maybe_uninitialized=no
CONFIGURE_ARGS+=	--enable-sna
MAKE_JOBS_UNSAFE=yes
PLIST_SUB+=	OLD="@comment "
EXTRA_PATCHES+=	${PATCHDIR}/extra-src__sna__sna_threads.c \
		${PATCHDIR}/extra-src_sna_kgem.c \
		${PATCHDIR}/extra-clang \
		${PATCHDIR}/extra-i915kms
LIB_DEPENDS+=	xcb-util:${PORTSDIR}/x11/xcb-util
.else
INTEL_VERSION=	2.7.1
INTEL_REVISION=	5
PLIST_SUB+=	OLD=""

EXTRA_PATCHES+=	${PATCHDIR}/extra-src_ch7017_ch7017.c \
		${PATCHDIR}/extra-src_i830_render.c \
		${PATCHDIR}/extra-src_ch7xxx_ch7xxx.c \
		${PATCHDIR}/extra-src_i830_video.c \
		${PATCHDIR}/extra-src_i810_driver.c \
		${PATCHDIR}/extra-src_i915_hwmc.c \
		${PATCHDIR}/extra-src_i810_hwmc.c \
		${PATCHDIR}/extra-src_i915_render.c \
		${PATCHDIR}/extra-src_i810_video.c \
		${PATCHDIR}/extra-src_i965_render.c \
		${PATCHDIR}/extra-src_i830_dri.c \
		${PATCHDIR}/extra-src_ivch_ivch.c \
		${PATCHDIR}/extra-src_i830_driver.c \
		${PATCHDIR}/extra-src_sil164_sil164.c \
		${PATCHDIR}/extra-src_i830_dvo.c \
		${PATCHDIR}/extra-src_tfp410_tfp410.c \
		${PATCHDIR}/extra-src_i830_i2c.c \
		${PATCHDIR}/extra-uxa_uxa-priv.h
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_NEW_XORG)
pre-configure:
.if !exists(${LOCALBASE}/lib/libkms.so)
	@${ECHO} "${PKGNAME}: Rebuild graphics/libdrm with the WITH_KMS option."
	@${FALSE}
.endif
.endif

.include <bsd.port.post.mk>
