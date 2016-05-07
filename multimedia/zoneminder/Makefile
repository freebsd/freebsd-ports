# Created by: bsam, based on ports by achix (1.23 & local camera stuff),
# $FreeBSD$

PORTNAME=	zoneminder
PORTVERSION=	1.25.0
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://www2.zoneminder.com/downloads/ \
		http://www.zoneminder.com/downloads/
DISTNAME=	ZoneMinder-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete security camera solution, fully web based with image analysis

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

RUN_DEPENDS=	${LOCALBASE}/bin/sudo:security/sudo
LIB_DEPENDS=	libnetpbm.so:graphics/netpbm \
		libpcre.so:devel/pcre \
		libavutil0.so:multimedia/ffmpeg0
BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-libwww>=0:www/p5-libwww \
		p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Archive-Tar>=0:archivers/p5-Archive-Tar \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		${LOCALBASE}/include/linux/videodev.h:multimedia/v4l_compat

USES=		jpeg perl5 shebangfix
GNU_CONFIGURE=	yes
USE_PHP=	json mysql session
USE_MYSQL=	yes
USE_RC_SUBR=	zoneminder
USE_GCC=	any
USE_PERL5=	run build
IGNORE_WITH_PHP=	70

CFLAGS+=	-I${LOCALBASE}/include/ffmpeg0 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/ffmpeg0
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} \
		--with-webdir=${WWWDIR}/data \
		--with-cgidir=${WWWDIR}/cgi-bin \
		--with-webgroup=${WWWGRP} \
		--with-webuser=${WWWOWN} \
		--enable-crashtrace=no \
		--with-ffmpeg=${LOCALBASE} \
		--enable-mmap=no \
		--with-extralibs=-lpthread

CONFIGURE_ENV=	ZM_DB_HOST=${DB_HOST} \
		ZM_DB_NAME=${DB_NAME} \
		ZM_DB_USER=${DB_USER} \
		ZM_DB_PASS=${DB_PASS} \
		ZM_SSL_LIB="openssl"  \
		ZM_LOGDIR=${M_LOGDIR} \
		ZM_RUNDIR=${M_RUNDIR} \
		ZM_TMPDIR=${M_TMPDIR}

DB_HOST?=	localhost
DB_NAME?=	zm
DB_USER?=	zmuser
DB_PASS?=	zmpass

#
# These variables default to to the defaults specified in the
# original distributed ZoneMinder/configure.ac
#
M_LOGDIR?=	/var/log/zm
M_RUNDIR?=	/var/run/zm
M_TMPDIR?=	/tmp/zm

PLIST_SUB=	ZM_LOGDIR=${M_LOGDIR}	\
		ZM_RUNDIR=${M_RUNDIR}	\
		ZM_TMPDIR=${M_TMPDIR}	\
		WEB_USER=${WWWOWN}	\
		WEB_GROUP=${WWWGRP}

SHEBANG_FILES=	scripts/zmdc.pl.in	\
		scripts/zmaudit.pl.in	\
		scripts/zmfilter.pl.in	\
		scripts/zmtrigger.pl.in	\
		scripts/zmx10.pl.in	\
		scripts/zmwatch.pl.in	\
		scripts/zmpkg.pl.in	\
		scripts/zmupdate.pl.in	\
		scripts/zmvideo.pl.in	\
		scripts/zmcontrol.pl.in	\
		scripts/zmtrack.pl.in

PORTDOCS=	AUTHORS \
		COPYING \
		ChangeLog \
		INSTALL \
		NEWS \
		README \
		README.FreeBSD \
		TODO

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-scripts_ZoneMinder_lib_ZoneMinder_Memory.pm.in
.endif

post-configure:

post-patch:
	${REINPLACE_CMD} -e 's,/bin:/usr/bin,/bin:/usr/bin:${LOCALBASE}/bin,g' ${WRKSRC}/scripts/*.pl.in
	${REINPLACE_CMD} -e 's,sudo,${LOCALBASE}/bin/sudo,g' ${WRKSRC}/scripts/zmpkg.pl.in
	${REINPLACE_CMD} \
		-e 's," == "," = ",g' \
		-e 's,lavcodec,lavcodec0,g' \
		-e 's,lavformat,lavformat0,g' \
		-e 's,lavutil,lavutil0,g' \
		-e 's,lavdevice,lavdevice0,g' \
		-e 's,lswscale,lswscale0,g' \
		-e 's,^FFMPEG_CFLAGS=.*,,g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,ZM_V4L2,ZM_HAS_V4L2,g' ${WRKSRC}//web/skins/classic/views/monitorprobe.php
	${REINPLACE_CMD} -e 's,chown,true chown,g' ${WRKSRC}/Makefile.in \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/web/Makefile.in

PKGMESSAGE=	${WRKDIR}/pkg-message
pre-build:
	${CP} ${FILESDIR}/videodev.h ${WRKSRC}/src
	${CP} ${FILESDIR}/zm_fbsd_camera.cpp ${WRKSRC}/src
	${TOUCH} ${WRKSRC}/src/zm_fbsd_camera.h
	${CP} ${FILESDIR}/README.FreeBSD ${WRKSRC}
	${CP} ${FILESDIR}/README.FreeBSD  ${PKGMESSAGE}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/zm.conf ${STAGEDIR}${PREFIX}/etc/zm.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/db/zm_create.sql ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} -p ${STAGEDIR}${M_TMPDIR}
	${MKDIR} -p ${STAGEDIR}${M_RUNDIR}
	${MKDIR} -p ${STAGEDIR}${M_LOGDIR}

.include <bsd.port.post.mk>
