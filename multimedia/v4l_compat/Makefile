# $FreeBSD$

PORTNAME=	v4l_compat
PORTREVISION=	3

COMMENT=	Video4Linux IOCTL header files

NO_BUILD=	yes
NO_ARCH=	yes

MASTERDIR=	${.CURDIR}/../../multimedia/libv4l
EXTRADIR=	${WRKSRC}/../linux
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
LIBV4L_SLAVE=	compat

BASE_HEADERS=	ivtv.h v4l2-controls.h \
		v4l2-common.h videodev2.h
DVB_HEADERS=	audio.h dmx.h frontend.h video.h
EXTRA_HEADERS=	ca.h net.h osd.h version.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/linux/dvb/
.for i in ${BASE_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/contrib/freebsd/include/linux/${i} \
		${STAGEDIR}${PREFIX}/include/linux/
.endfor
.for i in ${DVB_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/linux/dvb/${i} \
		${STAGEDIR}${PREFIX}/include/linux/dvb
.endfor
# V4L1 is dead in linux, however webcamd still supports it.
	${INSTALL_DATA} ${FILESDIR}/videodev.h \
		${STAGEDIR}${PREFIX}/include/linux/
# Extra dvb headers supplied taken from the linux kernel distfile.
# vdr and the gst dvb plugin need them at least
.for i in ${EXTRA_HEADERS}
	${INSTALL_DATA} ${EXTRADIR}/dvb/${i} \
		${STAGEDIR}${PREFIX}/include/linux/dvb/
.endfor

.include "${MASTERDIR}/Makefile"
