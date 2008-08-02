# New ports collection makefile for:   smilutils
# Date created:        26 january 2008
# Whom:                trebestie@gmail.com
#
# $FreeBSD$
#

PORTNAME=	smilutils
DISTVERSION=	0.3.2
PORTREVISION=	3
DISTVERSIONSUFFIX=	cvs
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rafan

MAINTAINER=	trebestie@gmail.com
COMMENT=	A collection of utilities to handle DV

LIB_DEPENDS=	dv.4:${PORTSDIR}/multimedia/libdv \
		png.5:${PORTSDIR}/graphics/png \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		mp3lame.0:${PORTSDIR}/audio/lame \
		vorbisenc.2:${PORTSDIR}/audio/libvorbis \
		quicktime.0:${PORTSDIR}/multimedia/libquicktime \
		ogg.5:${PORTSDIR}/audio/libogg

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:19 automake:19 autoconf:261 autoheader:261 libtool:15
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libxml2 libglade2
USE_ICONV=	yes
USE_SDL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/lqt -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib/libquicktime -L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

CONFIGURE_ARGS=	--with-avcodec=${LOCALBASE}/include/ffmpeg --enable-mp3lame --enable-vorbis \
		--with-ffmpeg=${LOCALBASE}/lib --with-x

MAN1=	image2raw.1 ppm2raw.1 ppm2webcam.1 raw2dv.1 \
	raw2image.1 raw2webcam.1 raw2yuv.1 rawmultiply.1 \
	rawplay.1 smil2raw.1 smil2wav.1 smil2yuv.1 \
	smilutils.1 xwd2raw.1

run-autotools:
	@cd ${WRKSRC} && ${SH} autogen.sh

# No tarball, we get cvs version.
# Based on an idea by Abel Chow <achow@transoft.net>
# who maintains tidy-devel port
# Look at http://lists.freebsd.org/pipermail/freebsd-ports/2007-September/043631.html
# for more informations

.if defined(MAINTAINER_MODE)

CVSROOT=	":pserver:anonymous@kino.cvs.sourceforge.net:/cvsroot/kino"

CVSROOT=	":pserver:anonymous@kino.cvs.sourceforge.net:/cvsroot/kino"
CVS_PASSFILE=	${WRKDIR}/temp-cvs-passfile

getcvs:
	${MKDIR} ${WRKDIR}/cvs
	${ECHO_CMD} ${CVSROOT} A > ${CVS_PASSFILE}
	cd ${WRKDIR}/cvs && \
	CVSROOT=${CVSROOT} CVS_PASSFILE=${CVS_PASSFILE} cvs -z3 co -P smilutils

tarball:
	${RM} -rf ${WRKDIR}/cvs/smilutils/CVSROOT
	${FIND} ${WRKDIR}/cvs -name CVS | ${XARGS} ${RM} -rf
	cd ${WRKDIR}/cvs &&     \
	${TAR} cfj ${_DISTDIR}${DISTFILES} smilutils

.endif

.include <bsd.port.mk>
