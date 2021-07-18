# Created by: Angel Carpintero <ack@telefonica.net>

# PORTNAME block
PORTNAME=	motion
PORTVERSION=	4.3.2
PORTREVISION=	1
DISTVERSIONPREFIX=	release-
CATEGORIES=	multimedia

# Maintainer block
MAINTAINER=	ports@blievers.net
COMMENT=	Motion detection application

# License block
LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/COPYING

# Dependencies
LIB_DEPENDS=	libwebp.so:graphics/webp \
		libmicrohttpd.so:www/libmicrohttpd

# USES block
USES=		autoreconf gmake jpeg localbase pkgconfig gettext

USE_GITHUB=	yes
GH_ACCOUNT=	Motion-Project
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-linuxthreads \
		--without-jpeg-mmx

# Standard bsd.port.mk variables
SUB_FILES=	pkg-message

# Packaging list block
PLIST_FILES=	bin/motion \
		man/man1/motion.1.gz \
		"@sample ${ETCDIR}/motion.conf.sample" \
		"@dir ${ETCDIR}/conf.d"
PORTDOCS=	*

PORTEXAMPLES=	camera1-dist.conf camera2-dist.conf \
		camera3-dist.conf camera4-dist.conf

# Options definitions
OPTIONS_DEFINE=		DOCS EXAMPLES FFMPEG MYSQL PGSQL SQLITE3
OPTIONS_DEFAULT=	WEBCAMD FFMPEG
OPTIONS_RADIO=		VIDEO
OPTIONS_RADIO_VIDEO=	BKTR PWCBSD WEBCAMD

BKTR_DESC=		BKTR based TV capture cards

PWCBSD_DESC=		PWCBSD based Webcams

VIDEO_DESC=		Video capture driver (Netcam support only if none selected)
WEBCAMD_DESC=		Webcams using webcamd

BKTR_CONFIGURE_WITH=	bktr
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

PWCBSD_BUILD_DEPENDS=	v4l_compat>=1.0.20060801:multimedia/v4l_compat
PWCBSD_RUN_DEPENDS=	pwcbsd>0:multimedia/pwcbsd
PWCBSD_CONFIGURE_WITH=	pwcbsd

SQLITE3_USES=		sqlite:3
SQLITE3_CONFIGURE_WITH=	sqlite3

WEBCAMD_BUILD_DEPENDS=	v4l_compat>=1.0.20060801:multimedia/v4l_compat
#  note: all configure --with-pwcbsd does is not shut off v4l support
WEBCAMD_CONFIGURE_WITH=	pwcbsd

.include <bsd.port.pre.mk>

.if ${JPEG_PORT} == "graphics/jpeg-turbo"
CONFIGURE_ARGS+=	--with-jpeg-turbo=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure.ac
# Fix pidfile path
	@${REINPLACE_CMD} -e \
		's|/run/motion|/run|' ${WRKSRC}/data/motion-dist.conf.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/motion ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/motion.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d
	${INSTALL_DATA} ${WRKSRC}/data/motion-dist.conf \
		${STAGEDIR}${ETCDIR}/motion.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/data/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
