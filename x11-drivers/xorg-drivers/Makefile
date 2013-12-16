# $FreeBSD$

PORTNAME=	xorg-drivers
PORTVERSION=	7.7
CATEGORIES=	x11-drivers
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org drivers meta-port

.MAKE.FreeBSD_UL=	yes

VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

NO_BUILD=	yes

INPUT_DRIVERS=		mouse \
			keyboard \
			acecad \
			elographics \
			hyperpen \
			joystick \
			magictouch \
			mutouch \
			penmount \
			synaptics \
			vmmouse \
			void

VIDEO_DRIVERS=		ati \
			mach64 \
			nv \
			r128 \
			vesa \
			apm \
			ark \
			chips \
			cyrix \
			dummy \
			fbdev \
			glint \
			i128 \
			i740 \
			mga \
			neomagic \
			newport \
			rendition \
			s3 \
			s3virge \
			savage \
			siliconmotion \
			sis \
			tdfx \
			tga \
			trident \
			tseng \
			vmware \
			voodoo

OPTIONS_DEFAULT=	MOUSE \
			KEYBOARD \
			ATI \
			MACH64 \
			NV \
			R128 \
			VESA

.for type in input video
. for a in ${${type:U}_DRIVERS}
OPTIONS_DEFINE+=	${a:U}
${a:U}_DESC=	Install ${a} ${type} driver
. endfor
.endfor

OPTIONS_DEFINE_i386=	INTEL OPENCHROME
OPTIONS_DEFAULT_i386=	INTEL OPENCHROME

OPTIONS_DEFINE_amd64:=	${OPTIONS_DEFINE_i386}
OPTIONS_DEFAULT_amd64:=	${OPTIONS_DEFAULT_i386}

OPTIONS_DEFINE_sparc64=	SUNFFB
OPTIONS_DEFAULT_sparc64=SUNFFB

OPTIONS_DEFINE_ia64=	OPENCHROME
OPTIONS_DEFAULT_ia64=	OPENCHROME

INTEL_DESC=		Install intel video driver
OPENCHROME_DESC=	Install openchrome video driver
SUNFFB_DESC=		Install sunffb video driver

# these drivers have a different module name compared to the plugin they install
QUIRKS=		keyboard:kbd

.include <bsd.port.options.mk>

# Manual add arch specific drivers so they be added to depend lines.
.if ${ARCH}==i386 || ${ARCH}==amd64
VIDEO_DRIVERS+=	intel openchrome
.endif

.if ${ARCH}==sparc64
VIDEO_DRIVERS+=	sunffb
.endif

.for type in input video
. for i in ${${type:U}_DRIVERS}
.  if ${PORT_OPTIONS:M${i:U}} != ""
.   if ${QUIRKS:M${i}\:*:C/.*://} != ""
RUN_DEPENDS+=	${${type:U}DIR}/${QUIRKS:M${i}\:*:C/.*://}_drv.so:${PORTSDIR}/x11-drivers/xf86-${type}-${i}
.   else
RUN_DEPENDS+=	${${type:U}DIR}/${i}_drv.so:${PORTSDIR}/x11-drivers/xf86-${type}-${i}
.   endif
.  endif
. endfor
.endfor

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/libdata/xorg
		${TOUCH} ${STAGEDIR}${PREFIX}/libdata/xorg/drivers

.include <bsd.port.mk>
