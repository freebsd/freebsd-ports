PORTNAME=	xorg-drivers
PORTVERSION=	7.7
PORTREVISION=	7
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org drivers meta-port
WWW=		https://www.x.org/

VIDEODIR=	${LOCALBASE}/lib/xorg/modules/drivers
INPUTDIR=	${LOCALBASE}/lib/xorg/modules/input

USES=		metaport

INPUT_DRIVERS=		egalax \
			elographics \
			evdev \
			joystick \
			keyboard \
			libinput \
			mouse \
			synaptics \
			void \
			wacom

VIDEO_DRIVERS=		ast \
			dummy \
			nv \
			scfb \
			vesa

OPTIONS_DEFAULT=	KEYBOARD \
			LIBINPUT \
			MOUSE \
			SCFB

.for type in input video
. for a in ${${type:tu}_DRIVERS}
OPTIONS_DEFINE+=	${a:tu}
${a:tu}_DESC=		Install ${a} ${type} driver
. endfor
.endfor

OPTIONS_DEFINE_amd64=	AMDGPU ATI INTEL VMMOUSE VMWARE
OPTIONS_DEFAULT_amd64=	VESA

OPTIONS_DEFINE_i386:=	${OPTIONS_DEFINE_amd64} GEODE
OPTIONS_DEFAULT_i386:=	${OPTIONS_DEFAULT_amd64}

AMDGPU_DESC=		Install amdgpu video driver
ATI_DESC=		Install ati (radeon) video driver
GEODE_DESC=		Install geode video driver
INTEL_DESC=		Install intel video driver
VMMOUSE_DESC=		Install vmmouse input driver
VMWARE_DESC=		Install vmware video driver

# these drivers have a different module name compared to the plugin they install
QUIRKS=		keyboard:kbd

.include <bsd.port.options.mk>

# Manual add arch specific drivers so they be added to depend lines.
.if ${ARCH}==i386 || ${ARCH}==amd64
INPUT_DRIVERS+= vmmouse
VIDEO_DRIVERS+=	amdgpu ati intel vmware
.endif

.if ${ARCH}==i386
VIDEO_DRIVERS+= geode
.endif

.for type in input video
. for i in ${${type:tu}_DRIVERS}
.  if ${PORT_OPTIONS:M${i:tu}} != ""
.   if ${QUIRKS:M${i}\:*:C/.*://} != ""
RUN_DEPENDS+=	${${type:tu}DIR}/${QUIRKS:M${i}\:*:C/.*://}_drv.so:x11-drivers/xf86-${type}-${i}
.   else
RUN_DEPENDS+=	${${type:tu}DIR}/${i}_drv.so:x11-drivers/xf86-${type}-${i}
.   endif
.  endif
. endfor
.endfor

.include <bsd.port.mk>
