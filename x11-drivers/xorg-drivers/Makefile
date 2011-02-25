# New ports collection makefile for:    xorg-drivers
# Date created:				Jun 22 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-drivers
PORTVERSION=	7.5.1
CATEGORIES=	x11-drivers
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org drivers meta-port

VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

NO_BUILD=	yes

.if !defined(ARCH)
ARCH!=  /usr/bin/uname -p
.endif

VIDEO_ON=	ati \
		mach64 \
		nv \
		r128 \
		radeonhd \
		vesa

.if ${ARCH} == "sparc64"
VIDEO_ON+=	sunffb
.elif ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64"
VIDEO_ON+=	openchrome
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
VIDEO_ON+=	intel
.endif

VIDEO_OFF=	apm ark \
		chips cirrus cyrix \
		dummy \
		fbdev \
		glint \
		i128 i740 imstt \
		mga \
		neomagic newport \
		rendition \
		s3 s3virge savage siliconmotion	sis \
		tdfx tga trident tseng \
		via vmware voodoo

VIDEO_EXCL=	via:openchrome

INPUT_ON=	mouse \
		keyboard
INPUT_OFF=	acecad \
		citron \
		elographics \
		fpit \
		hyperpen \
		joystick \
		magictouch mutouch \
		penmount \
		synaptics \
				vmmouse void

QUIRKS=		keyboard:kbd jamstudio:js_x

.if defined(XORG_COMPLETE)
. for type in input video
${type:U}_ON:=	${${type:U}_ON} ${${type:U}_OFF}
${type:U}_OFF=	# nil
.  for i in ${${type:U}_EXCL}
B=	${i:C/.*://}
${type:U}_ON:=	${${type:U}_ON:C/${B}//}
${type:U}_OFF:=	${${type:U}_OFF} ${B}
.  endfor
. endfor
.endif

.for default in on off
. for type in input video
.  for i in ${${type:U}_${default:U}}
OPTIONS+=	${i:U} "Install ${i} ${type} driver" ${default}
.  endfor
. endfor
.endfor

.include <bsd.port.pre.mk>

.for i in ${VIDEO_EXCL}
A=	${i:C/:.*//}
B=	${i:C/.*://}
. if defined(WITH_${B:U}) && !defined(WITHOUT_${A:U})
DRV_CONFLICTS+=	${i}
. endif
.endfor

.if defined(DRV_CONFLICTS)
IGNORE=		can't be installed because of conflicting drivers (${DRV_CONFLICTS}). Re-run make config.
.endif

.for default in on off
. for type in input video
.  for i in ${${type:U}_${default:U}}
DEFAULT=${default}
.   if (${DEFAULT} == "on" && !defined(WITHOUT_${i:U})) || (${DEFAULT} == "off" && defined(WITH_${i:U}))
.    if ${QUIRKS:M${i}\:*:C/.*://} != ""
RUN_DEPENDS+=	${${type:U}DIR}/${QUIRKS:M${i}\:*:C/.*://}_drv.so:${PORTSDIR}/x11-drivers/xf86-${type}-${i}
.    else
RUN_DEPENDS+=	${${type:U}DIR}/${i}_drv.so:${PORTSDIR}/x11-drivers/xf86-${type}-${i}
.    endif
.   endif
.  endfor
. endfor
.endfor

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/drivers

.include <bsd.port.post.mk>
