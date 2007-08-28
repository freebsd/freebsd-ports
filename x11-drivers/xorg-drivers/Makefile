# New ports collection makefile for:    xorg-drivers
# Date created:				Jun 22 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-drivers
PORTVERSION=	7.2
PORTREVISION=	1
CATEGORIES=	x11-drivers
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org drivers meta-port

VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

NO_BUILD=	yes

VIDEO_ON=	ati \
		i810 \
		nv \
		vesa vga via
VIDEO_OFF=	apm ark				\
		chips cirrus cyrix		\
		dummy \
		fbdev \
		glint \
		i128 i740 imstt	\
		mga \
		neomagic newport nsc \
		rendition \
		s3 s3virge savage siliconmotion	sis \
		tdfx tga trident tseng \
		vmware voodoo \
		sunffb

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
		void

.for default in on off
. for type in input video
.  for i in ${${type:U}_${default:U}}
OPTIONS+=	${i:U} "Install ${i} ${type} driver" ${default}
.  endfor
. endfor
.endfor

.include <bsd.port.pre.mk>

.for default in on off
. for type in input video
.  for i in ${${type:U}_${default:U}}
DEFAULT=${default}
.   if (${DEFAULT} == "on" && !defined(WITHOUT_${i:U})) || (${DEFAULT} == "off" &&  defined(WITH_${i:U}))
RUN_DEPENDS+=	${${type:U}DIR}/${i:C/jamstudio/js_x/}_drv.so:${PORTSDIR}/x11-drivers/xf86-${type}-${i}
.   endif
.  endfor
. endfor
.endfor

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/drivers

.include <bsd.port.post.mk>
