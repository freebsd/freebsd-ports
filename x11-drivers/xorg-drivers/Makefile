# $FreeBSD$

PORTNAME=	xorg-drivers
PORTVERSION=	7.7
PORTREVISION=	3
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org drivers meta-port

VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

USES=		metaport

INPUT_DRIVERS=		mouse \
			keyboard \
			acecad \
			elographics \
			hyperpen \
			joystick \
			mutouch \
			penmount \
			synaptics \
			vmmouse \
			void \
			wacom

VIDEO_DRIVERS=		mach64 \
			nv \
			r128 \
			vesa \
			apm \
			ark \
			chips \
			dummy \
			fbdev \
			glint \
			i128 \
			i740 \
			mga \
			neomagic \
			rendition \
			s3 \
			s3virge \
			savage \
			siliconmotion \
			sis \
			tdfx \
			trident \
			tseng \
			vmware \
			voodoo

OPTIONS_DEFAULT=	MOUSE \
			KEYBOARD \
			MACH64 \
			NV \
			R128 \
			VESA

.for type in input video
. for a in ${${type:tu}_DRIVERS}
OPTIONS_DEFINE+=	${a:tu}
${a:tu}_DESC=	Install ${a} ${type} driver
. endfor
.endfor

OPTIONS_DEFINE_i386=	ATI INTEL OPENCHROME
OPTIONS_DEFAULT_i386=	ATI INTEL OPENCHROME

OPTIONS_DEFINE_amd64:=	${OPTIONS_DEFINE_i386}
OPTIONS_DEFAULT_amd64:=	${OPTIONS_DEFAULT_i386}

OPTIONS_DEFINE_sparc64=	SUNFFB
OPTIONS_DEFAULT_sparc64=SUNFFB

OPTIONS_DEFINE_ia64=	OPENCHROME
OPTIONS_DEFAULT_ia64=	OPENCHROME

ATI_DESC=		Install ati video driver
INTEL_DESC=		Install intel video driver
OPENCHROME_DESC=	Install openchrome video driver
SUNFFB_DESC=		Install sunffb video driver

# these drivers have a different module name compared to the plugin they install
QUIRKS=		keyboard:kbd

.include <bsd.port.options.mk>

# Manual add arch specific drivers so they be added to depend lines.
.if ${ARCH}==i386 || ${ARCH}==amd64
VIDEO_DRIVERS+=	ati intel openchrome
.endif

.if ${ARCH}==sparc64
VIDEO_DRIVERS+=	sunffb
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
