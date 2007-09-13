# New ports collection makefile for:    xorg-drivers
# Date created:				Jun 22 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-drivers
PORTVERSION=	7.3
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
		i810 \
		nv \
		vesa vga via
VIDEO_OFF=	apm ark \
		chips cirrus cyrix \
		dummy \
		fbdev \
		glint \
		i128 i740 imstt	intel \
		mga \
		neomagic newport nsc \
		rendition \
		s3 s3virge savage siliconmotion	sis \
		tdfx tga trident tseng \
		vmware voodoo

.if ${ARCH} == "sparc64"
VIDEO_ON+=	sunffb
.else
VIDEO_OFF+=	sunffb
.endif

INPUT_ON=	mouse \
		keyboard
INPUT_OFF=	acecad \
		calcomp citron \
		digitaledge dmc	dynapro \
		elo2300	elographics \
		fpit \
		hyperpen \
		jamstudio joystick \
		magellan magictouch microtouch mutouch \
		palmax penmount \
		spaceorb summa \
		tek4957 \
		vmmouse void

QUIRKS=		keyboard:kbd jamstudio:js_x

.if defined(XORG_COMPLETE)
. for type in input video
${type:U}_ON:=	${${type:U}_ON} ${${type:U}_OFF}
${type:U}_OFF=	# nil
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

.if defined(WITH_INTEL) && !defined(WITHOUT_I810)
IGNORE=		You can't choose both i810 and intel drivers as they are conflicting
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
