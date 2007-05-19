# New ports collection makefile for:    xorg-drivers
# Date created:				Jun 22 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-drivers
PORTVERSION=	7.2
CATEGORIES=	x11-drivers
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org drivers meta-port

USE_X_PREFIX=	yes
VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

RUN_DEPENDS=	${INPUTDIR}/acecad_drv.so:${PORTSDIR}/x11-drivers/xf86-input-acecad \
		${INPUTDIR}/calcomp_drv.so:${PORTSDIR}/x11-drivers/xf86-input-calcomp \
		${INPUTDIR}/citron_drv.so:${PORTSDIR}/x11-drivers/xf86-input-citron \
		${INPUTDIR}/digitaledge_drv.so:${PORTSDIR}/x11-drivers/xf86-input-digitaledge \
		${INPUTDIR}/dmc_drv.so:${PORTSDIR}/x11-drivers/xf86-input-dmc \
		${INPUTDIR}/dynapro_drv.so:${PORTSDIR}/x11-drivers/xf86-input-dynapro \
		${INPUTDIR}/elo2300_drv.so:${PORTSDIR}/x11-drivers/xf86-input-elo2300 \
		${INPUTDIR}/elographics_drv.so:${PORTSDIR}/x11-drivers/xf86-input-elographics \
		${INPUTDIR}/fpit_drv.so:${PORTSDIR}/x11-drivers/xf86-input-fpit \
		${INPUTDIR}/hyperpen_drv.so:${PORTSDIR}/x11-drivers/xf86-input-hyperpen \
		${INPUTDIR}/js_x_drv.so:${PORTSDIR}/x11-drivers/xf86-input-jamstudio \
		${INPUTDIR}/joystick_drv.so:${PORTSDIR}/x11-drivers/xf86-input-joystick \
		${INPUTDIR}/keyboard_drv.so:${PORTSDIR}/x11-drivers/xf86-input-keyboard \
		${INPUTDIR}/magellan_drv.so:${PORTSDIR}/x11-drivers/xf86-input-magellan \
		${INPUTDIR}/magictouch_drv.so:${PORTSDIR}/x11-drivers/xf86-input-magictouch \
		${INPUTDIR}/microtouch_drv.so:${PORTSDIR}/x11-drivers/xf86-input-microtouch \
		${INPUTDIR}/mouse_drv.so:${PORTSDIR}/x11-drivers/xf86-input-mouse \
		${INPUTDIR}/mutouch_drv.so:${PORTSDIR}/x11-drivers/xf86-input-mutouch \
		${INPUTDIR}/palmax_drv.so:${PORTSDIR}/x11-drivers/xf86-input-palmax \
		${INPUTDIR}/penmount_drv.so:${PORTSDIR}/x11-drivers/xf86-input-penmount \
		${INPUTDIR}/spaceorb_drv.so:${PORTSDIR}/x11-drivers/xf86-input-spaceorb \
		${INPUTDIR}/summa_drv.so:${PORTSDIR}/x11-drivers/xf86-input-summa \
		${INPUTDIR}/tek4957_drv.so:${PORTSDIR}/x11-drivers/xf86-input-tek4957 \
		${INPUTDIR}/void_drv.so:${PORTSDIR}/x11-drivers/xf86-input-void \
		${VIDEODIR}/apm_drv.so:${PORTSDIR}/x11-drivers/xf86-video-apm \
		${VIDEODIR}/ark_drv.so:${PORTSDIR}/x11-drivers/xf86-video-ark \
		${VIDEODIR}/ati_drv.so:${PORTSDIR}/x11-drivers/xf86-video-ati \
		${VIDEODIR}/chips_drv.so:${PORTSDIR}/x11-drivers/xf86-video-chips \
		${VIDEODIR}/cirrus_drv.so:${PORTSDIR}/x11-drivers/xf86-video-cirrus \
		${VIDEODIR}/cyrix_drv.so:${PORTSDIR}/x11-drivers/xf86-video-cyrix \
		${VIDEODIR}/dummy_drv.so:${PORTSDIR}/x11-drivers/xf86-video-dummy \
		${VIDEODIR}/fbdev_drv.so:${PORTSDIR}/x11-drivers/xf86-video-fbdev \
		${VIDEODIR}/glint_drv.so:${PORTSDIR}/x11-drivers/xf86-video-glint \
		${VIDEODIR}/i128_drv.so:${PORTSDIR}/x11-drivers/xf86-video-i128 \
		${VIDEODIR}/i740_drv.so:${PORTSDIR}/x11-drivers/xf86-video-i740 \
		${VIDEODIR}/i810_drv.so:${PORTSDIR}/x11-drivers/xf86-video-i810 \
		${VIDEODIR}/imstt_drv.so:${PORTSDIR}/x11-drivers/xf86-video-imstt \
		${VIDEODIR}/mga_drv.so:${PORTSDIR}/x11-drivers/xf86-video-mga \
		${VIDEODIR}/neomagic_drv.so:${PORTSDIR}/x11-drivers/xf86-video-neomagic \
		${VIDEODIR}/newport_drv.so:${PORTSDIR}/x11-drivers/xf86-video-newport \
		${VIDEODIR}/nsc_drv.so:${PORTSDIR}/x11-drivers/xf86-video-nsc \
		${VIDEODIR}/nv_drv.so:${PORTSDIR}/x11-drivers/xf86-video-nv \
		${VIDEODIR}/rendition_drv.so:${PORTSDIR}/x11-drivers/xf86-video-rendition \
		${VIDEODIR}/s3_drv.so:${PORTSDIR}/x11-drivers/xf86-video-s3 \
		${VIDEODIR}/s3virge_drv.so:${PORTSDIR}/x11-drivers/xf86-video-s3virge \
		${VIDEODIR}/savage_drv.so:${PORTSDIR}/x11-drivers/xf86-video-savage \
		${VIDEODIR}/siliconmotion_drv.so:${PORTSDIR}/x11-drivers/xf86-video-siliconmotion \
		${VIDEODIR}/sis_drv.so:${PORTSDIR}/x11-drivers/xf86-video-sis \
		${VIDEODIR}/tdfx_drv.so:${PORTSDIR}/x11-drivers/xf86-video-tdfx \
		${VIDEODIR}/tga_drv.so:${PORTSDIR}/x11-drivers/xf86-video-tga \
		${VIDEODIR}/trident_drv.so:${PORTSDIR}/x11-drivers/xf86-video-trident \
		${VIDEODIR}/tseng_drv.so:${PORTSDIR}/x11-drivers/xf86-video-tseng \
		${VIDEODIR}/vesa_drv.so:${PORTSDIR}/x11-drivers/xf86-video-vesa \
		${VIDEODIR}/vga_drv.so:${PORTSDIR}/x11-drivers/xf86-video-vga \
		${VIDEODIR}/via_drv.so:${PORTSDIR}/x11-drivers/xf86-video-via \
		${VIDEODIR}/vmware_drv.so:${PORTSDIR}/x11-drivers/xf86-video-vmware \
		${VIDEODIR}/voodoo_drv.so:${PORTSDIR}/x11-drivers/xf86-video-voodoo \

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
RUN_DEPENDS+= 	${VIDEODIR}/sunffb_drv.so:${PORTSDIR}/x11-drivers/xf86-video-sunffb
.endif

NO_BUILD=	yes

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/drivers

.include <bsd.port.post.mk>
