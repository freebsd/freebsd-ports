# Created by: Angel Carpintero <ack@telefonica.net>
# $FreeBSD$

PORTNAME=	motion
PORTVERSION=	4.0.1
DISTVERSIONPREFIX=	release-
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motion detection application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Motion-Project

USES=		autoreconf gmake jpeg localbase pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-linuxthreads \
		--without-jpeg-mmx

KMODDIR?=	/boot/modules
.if ${KMODDIR} == /boot/kernel
KMODDIR=	/boot/modules
.endif

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/motion \
		man/man1/motion.1.gz \
		"@sample etc/motion.conf.sample"
PORTDOCS=	CHANGELOG CREDITS README.md README.FreeBSD \
		motion_guide.html
PORTEXAMPLES=	camera1-dist.conf camera2-dist.conf \
		camera3-dist.conf camera4-dist.conf

OPTIONS_DEFINE=		DOCS EXAMPLES FFMPEG MYSQL PGSQL SQLITE3
OPTIONS_SINGLE=		VIDEO
OPTIONS_SINGLE_VIDEO=	BKTR PWCBSD
OPTIONS_DEFAULT=	BKTR FFMPEG
VIDEO_DESC=		Video capture driver

BKTR_DESC=		BKTR based TV capture cards
BKTR_CONFIGURE_WITH=	bktr

PWCBSD_DESC=		PWCBSD based Webcams
PWCBSD_BUILD_DEPENDS=	v4l_compat>=1.0.20060801:multimedia/v4l_compat
PWCBSD_RUN_DEPENDS=	${KMODDIR}/pwc.ko:multimedia/pwcbsd
PWCBSD_CONFIGURE_WITH=	pwcbsd

FFMPEG_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	--with-ffmpeg=${LOCALBASE}
FFMPEG_CONFIGURE_OFF=	--without-ffmpeg

MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql-lib=${LOCALBASE}/lib/mysql \
			--with-mysql-include=${LOCALBASE}/include/mysql
MYSQL_CONFIGURE_OFF=	--without-mysql

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql-lib=${LOCALBASE}/lib \
			--with-pgsql-include=${LOCALBASE}/include
PGSQL_CONFIGURE_OFF=	--without-pgsql

SQLITE3_USES=		sqlite:3
SQLITE3_CONFIGURE_WITH=	sqlite3

.include <bsd.port.pre.mk>

.if ${JPEG_PORT} == "graphics/jpeg-turbo"
CONFIGURE_ARGS+=	--with-jpeg-turbo=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure.ac
# Fix pidfile path
	@${REINPLACE_CMD} -e \
		's|/run/motion|/run|' ${WRKSRC}/motion-dist.conf.in
# Fix warnings about mismatched format specifiers (Fixed upstream in dbd7282)
	@${REINPLACE_CMD} -e \
		's|%hd|%d|g;s|%hu|%u|g;s|%Zu|%zu|g' ${WRKSRC}/webhttpd.c ${WRKSRC}/stream.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/motion ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/motion.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/motion-dist.conf \
		${STAGEDIR}${PREFIX}/etc/motion.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
