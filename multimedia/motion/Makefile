# New ports collection makefile for:	motion
# Date created:				22 Dec 2005
# Whom:					Angel Carpintero <ack@telefonica.net>
#
# $FreeBSD$
#

PORTNAME=	motion
PORTVERSION=	3.2.11.1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20-%203.2/${PORTVERSION}

PATCH_SITES=	http://www.lavrsen.dk/twiki/pub/Motion/FreeBSDPatch/
PATCHFILES=	motion-3.2.11.1.port-freebsd.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ack@telefonica.net
COMMENT=	A motion detection application

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		avformat.1:${PORTSDIR}/multimedia/ffmpeg

ONLY_FOR_ARCHS=	i386 amd64

MAN1=		motion.1

USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MANCOMPRESSED=	no

MAN1=		motion.1
PORTDOCS=	CHANGELOG CREDITS README.FreeBSD README \
		motion_guide.html
PORTEXAMPLES=	motion-dist.conf thread1.conf thread2.conf \
		thread3.conf thread4.conf

OPTIONS=	PWCBSD "PWCBSD based Webcams (disables BKTR)" off \
		BKTR "Support for TV Capture cards" on \
		LINUXTHREADS "Use LinuxThreads" off

.include <bsd.port.pre.mk>

.if !defined(WITH_BKTR) && !defined(WITH_PWCBSD)
CFLAGS+=	-DWITHOUT_V4L
.endif

.if defined(WITH_PWCBSD)
CONFIGURE_ARGS=	--with-pwcbsd
BUILD_DEPENDS+=	v4l_compat>=1.0.20060801:${PORTSDIR}/multimedia/v4l_compat
RUN_DEPENDS+=	/boot/modules/pwc.ko:${PORTSDIR}/multimedia/pwcbsd
.endif

.if defined(WITH_LINUXTHREADS) || ${OSVERSION} < 504000
CONFIGURE_ARGS=	--with-linuxthreads
LIB_DEPENDS+=	lthread.[35]:${PORTSDIR}/devel/linuxthreads
.endif

post-install:
.if !exists(${PREFIX}/etc/motion.conf)
	${INSTALL_DATA} ${PREFIX}/etc/motion.conf.sample ${PREFIX}/etc/motion.conf
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.init-FreeBSD.sh ${PREFIX}/etc/rc.d/${PORTNAME}

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples are installed in ${EXAMPLESDIR}."
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Docs are installed in ${DOCSDIR}."
.endif

.if defined(WITH_BKTR)
	@${ECHO_MSG} "==============================================================================="
	@${ECHO_MSG} "Please make sure you have bktr(4) kernel support."
	@${ECHO_MSG} "==============================================================================="
.endif

.if defined(WITH_PWCBSD)
	@${ECHO_MSG} "==============================================================================="
	@${ECHO_MSG} "Please make sure you have pwcbsd compiled with mmap support."
	@${ECHO_MSG} "==============================================================================="
.endif

.include <bsd.port.post.mk>
