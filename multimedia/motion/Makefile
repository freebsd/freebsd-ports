# Created by: Angel Carpintero <ack@telefonica.net>
# $FreeBSD$

PORTNAME=	motion
PORTVERSION=	3.2.12
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20-%20${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motion detection application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	FFMPEG MYSQL PGSQL DOCS EXAMPLES
OPTIONS_SINGLE=	VIDEO
OPTIONS_SINGLE_VIDEO=	BKTR PWCBSD
OPTIONS_DEFAULT=	BKTR FFMPEG
VIDEO_DESC=	Video capture driver. Choose one of BKTR or PWCBSD
BKTR_DESC=	BKTR based TV capture cards
PWCBSD_DESC=	PWCBSD based Webcams

USES=		autoreconf gmake jpeg
GNU_CONFIGURE=	yes

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	CHANGELOG CREDITS README README.FreeBSD \
		motion_guide.html
PORTEXAMPLES=	motion-dist.conf thread1.conf thread2.conf \
		thread3.conf thread4.conf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBKTR}
CONFIGURE_ARGS+=--with-bktr
.else
CONFIGURE_ARGS+=--without-bktr
.endif

.if ${PORT_OPTIONS:MPWCBSD}
# Location /boot/modules is hard coded in the pwc port, so use it here too
KMODDIR=	/boot/modules
BUILD_DEPENDS+=	v4l_compat>=1.0.20060801:multimedia/v4l_compat
RUN_DEPENDS+=	${KMODDIR}/pwc.ko:multimedia/pwcbsd
CONFIGURE_ARGS+=--with-pwcbsd
.else
CONFIGURE_ARGS+=--without-pwcbsd
.endif

CONFIGURE_ARGS+=--without-linuxthreads

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavformat0.so:multimedia/ffmpeg0
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
USES+=		pgsql
CONFIGURE_ARGS+=--with-pgsql-lib=${LOCALBASE}/lib \
		--with-pgsql-include=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--without-pgsql
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure.in
# Resolve name collision with jpeg-8
	@${REINPLACE_CMD} -e \
		's|jpeg_mem_dest|local_jpeg_mem_dest|' ${WRKSRC}/picture.c
# Fix pidfile path
	@${REINPLACE_CMD} -e \
		's|/run/motion|/run|' ${WRKSRC}/motion-dist.conf.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/motion ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/motion.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/motion-dist.conf \
		${STAGEDIR}${PREFIX}/etc/motion.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
