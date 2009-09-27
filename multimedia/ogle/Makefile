# New ports collection makefile for:	ogle
# Date created:				Tue Oct 16 18:35:39 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogle
PORTVERSION=	0.9.2
PORTREVISION=	12
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Open DVD player that supports DVD menus

LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		dvdread.4:${PORTSDIR}/multimedia/libdvdread \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		mad.2:${PORTSDIR}/audio/libmad \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_AUTOTOOLS=	libtool:22
USE_XORG=	x11 xext sm
USE_SUBMAKE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-libjpeg=${LOCALBASE} \
		--with-dvdread=${LOCALBASE} \
		--with-libmad=${LOCALBASE} \
		--with-liba52=${LOCALBASE}
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

DEFAULT_DVD_DEVICE?=	/dev/acd0

MAN1=	ogle.1
MAN5=	oglerc.5

.include <bsd.port.pre.mk>

post-patch:
.ifdef(WITH_DVD_DEVICE)
	@${REINPLACE_CMD} -E -e "s|(DEFAULT_DVD_DEVICE=\")/dev/acd0c(\")|\1${WITH_DVD_DEVICE}\2|" \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.else
	@${REINPLACE_CMD} -E -e "s|(DEFAULT_DVD_DEVICE=\")/dev/acd0c(\")|\1${DEFAULT_DVD_DEVICE}\2|" \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/scripts/ogle.in
# hack to make ogle work with liba52 + djbfft
# CFLAGS safeness
	@${REINPLACE_CMD} -E -e 's|(-la52)|\1 ${LIBA52_DEP_LIBS}|; \
		s,(X?CFLAGS[[:space:]]*=[[:space:]]*"\$$CFLAGS).*(-(fomit-frame-pointer|funroll-loops|march|mcpu)).*",\1",' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@${TOUCH} `${FIND} -E ${WRKSRC} -regex ".*Makefile\.(am|in)"`
	@${TOUCH} ${WRKSRC}/configure.in ${WRKSRC}/configure

# XXX due to gcc-3.4 (20040706) bug in preprocessing of inline functions,
# this needs at least -O2 to compile. Fails with -O
CFLAGS+=	-O2

# hack to make ogle work with liba52 + djbfft
.if exists(${LOCALBASE}/lib/liba52.la)
LIBA52_DEP_LIBS!=	${GREP} dependency_libs= ${LOCALBASE}/lib/liba52.la | ${CUT} -d \' -f 2
.else
LIBA52_DEP_LIBS=
.endif

.if ${ARCH} == "i386"
. if (defined(MACHINE_CPU) && ${MACHINE_CPU:Mi486} == "i486")
WITH_OPTIMIZED_BYTESWAP=yes
. endif

. if defined(WITH_OPTIMIZED_BYTESWAP)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-include:ogle_endian.h
. endif
.endif

pre-everything::
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===> The default DVD device is ${DEFAULT_DVD_DEVICE}'
	@${ECHO_MSG} "===> You can choose any DVD device at Ogle's command line"
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif
.ifndef(WITH_OPTIMIZED_BYTESWAP)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_OPTIMIZED_BYTESWAP to use optimized byteswap'
	@${ECHO_MSG} '===> routines. This works only in the i386 architecture, and'
	@${ECHO_MSG} '===> only with 486 processors and above.'
.endif

.include <bsd.port.post.mk>
