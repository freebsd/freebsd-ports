PORTNAME=	v4l_compat

COMMENT=	Video4Linux IOCTL header files

NO_BUILD=	yes
NO_ARCH=	yes

MASTERDIR=	${.CURDIR}/../libv4l
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

BASE_HEADERS= \
	linux/cec.h \
	linux/cec-funcs.h \
	linux/const.h \
	linux/dvb/audio.h \
	linux/dvb/ca.h \
	linux/dvb/dmx.h \
	linux/dvb/frontend.h \
	linux/dvb/net.h \
	linux/dvb/osd.h \
	linux/dvb/version.h \
	linux/dvb/video.h \
	linux/ivtv.h \
	linux/lirc.h \
	linux/media.h \
	linux/media-bus-format.h \
	linux/v4l2-common.h \
	linux/v4l2-controls.h \
	linux/v4l2-mediabus.h \
	linux/v4l2-subdev.h \
	linux/videodev2.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/linux/dvb

.for F in ${BASE_HEADERS}
	${INSTALL_DATA} \
		${LINUXDIR}/include/uapi/${F} \
		${STAGEDIR}${PREFIX}/include/${F}
.endfor

# V4L1 is dead in upstream Linux, however libv4l still supports it.
	${INSTALL_DATA} \
		${FILESDIR}/videodev.h \
		${STAGEDIR}${PREFIX}/include/linux/

# Install types header file
	${INSTALL_DATA} \
		${FILESDIR}/types.h \
		${STAGEDIR}${PREFIX}/include/linux/

.include "${MASTERDIR}/Makefile"
