# Created by: Angel Carpintero <ack@telefonica.net>
# $FreeBSD$

PORTNAME=	motion
PORTVERSION=	3.2.12
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20-%20${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motion detection application

BROKEN=		Fails to build

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	FFMPEG MYSQL PGSQL DOCS EXAMPLES
OPTIONS_SINGLE=	VIDEO
OPTIONS_SINGLE_VIDEO=	BKTR PWCBSD
OPTIONS_DEFAULT=	BKTR FFMPEG
VIDEO_DESC=	Video capture driver. Choose one of BKTR or PWCBSD
BKTR_DESC=	BKTR based TV capture cards
PWCBSD_DESC=	PWCBSD based Webcams

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		motion.1
PORTDOCS=	CHANGELOG CREDITS README README.FreeBSD \
		motion_guide.html
PORTEXAMPLES=	motion-dist.conf thread1.conf thread2.conf \
		thread3.conf thread4.conf

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBKTR}
CONFIGURE_ARGS+=--with-bktr
CFLAGS+=	-DWITHOUT_V4L
.else
CONFIGURE_ARGS+=--without-bktr
.endif

.if ${PORT_OPTIONS:MPWCBSD}
BUILD_DEPENDS+=	v4l_compat>=1.0.20060801:${PORTSDIR}/multimedia/v4l_compat
RUN_DEPENDS+=	/boot/modules/pwc.ko:${PORTSDIR}/multimedia/pwcbsd
CONFIGURE_ARGS+=--with-pwcbsd
CFLAGS+=	-DWITHOUT_V4L
.else
CONFIGURE_ARGS+=--without-pwcbsd
.endif

CONFIGURE_ARGS+=--without-linuxthreads

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avformat:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=--with-ffmpeg=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-ffmpeg
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-include=${LOCALBASE}/include/mysql
.else
CONFIGURE_ARGS+=--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql-lib=${LOCALBASE}/lib \
		--with-pgsql-include=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--without-pgsql
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure.in
# Resolve name collision with jpeg-8
	@${REINPLACE_CMD} -e \
		's|jpeg_mem_dest|local_jpeg_mem_dest|' ${WRKSRC}/picture.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/motion ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/motion.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/motion.init-FreeBSD.sh \
		${PREFIX}/etc/rc.d/motion
	${INSTALL_DATA} ${WRKSRC}/motion-dist.conf \
		${PREFIX}/etc/motion.conf.sample
.if !exists(${PREFIX}/etc/motion.conf)
	${INSTALL_DATA} ${PREFIX}/etc/motion.conf.sample \
		${PREFIX}/etc/motion.conf
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
