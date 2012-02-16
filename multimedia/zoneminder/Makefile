# New ports collection makefile for:	multimedia/zoneminder
# Date created:				2011-04-08
# Whom:					bsam, based on ports by achix (1.23 & local camera stuff),
#					Richard Lee and Electric Messiah
# $FreeBSD$
#

PORTNAME=	zoneminder
PORTVERSION=	1.24.4
PORTREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	http://www2.zoneminder.com/downloads/ \
		http://www.zoneminder.com/downloads/
DISTNAME=	ZoneMinder-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete security camera solution, fully web based with image analysis

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/sudo:${PORTSDIR}/security/sudo
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		netpbm.1:${PORTSDIR}/graphics/netpbm \
		pcre.1:${PORTSDIR}/devel/pcre \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg
BUILD_DEPENDS=	${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php5-extensions \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER} \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
		${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat

GNU_CONFIGURE=	yes
USE_PHP=	json mysql session
USE_PERL5=	yes
USE_MYSQL=	yes
USE_RC_SUBR=	zoneminder

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
		ZM_SSL_LIB="openssl"

DB_HOST?=	localhost
DB_NAME?=	zm
DB_USER?=	zmuser
DB_PASS?=	zmpass

PLIST_SUB=	WWWDIR_REL=${WWWDIR_REL}

MAN3PREFIX?=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		ZoneMinder::Trigger::Connection.3 \
		ZoneMinder::Control::Ncs370.3 \
		ZoneMinder::Trigger::Channel::Serial.3 \
		ZoneMinder.3 \
		ZoneMinder::Config.3 \
		ZoneMinder::Control::mjpgStreamer.3 \
		ZoneMinder::Control::PanasonicIP.3 \
		ZoneMinder::Base.3 \
		ZoneMinder::Trigger::Channel::Unix.3 \
		ZoneMinder::Control::AxisV2.3 \
		ZoneMinder::Trigger::Channel.3 \
		ZoneMinder::Memory.3 \
		ZoneMinder::Trigger::Channel::File.3 \
		ZoneMinder::Database.3 \
		ZoneMinder::Control::PelcoD.3 \
		ZoneMinder::Control::Visca.3 \
		ZoneMinder::Trigger::Channel::Inet.3 \
		ZoneMinder::Trigger::Connection::Example.3 \
		ZoneMinder::Trigger::Channel::Spawning.3 \
		ZoneMinder::Control.3 \
		ZoneMinder::General.3 \
		ZoneMinder::Trigger::Channel::Handle.3 \
		ZoneMinder::Debug.3 \
		ZoneMinder::ConfigAdmin.3 \
		ZoneMinder::ConfigData.3

post-configure:
	${MV} ${WRKSRC}/zm.conf ${WRKSRC}/zm.conf.sample

post-patch:
	${REINPLACE_CMD} -e 's,/bin:/usr/bin,/bin:/usr/bin:${LOCALBASE}/bin,g' ${WRKSRC}/scripts/*.pl.in
	${REINPLACE_CMD} -e 's,sudo,${LOCALBASE}/bin/sudo,g' ${WRKSRC}/scripts/zmpkg.pl.in
	${REINPLACE_CMD} -e 's," == "," = ",g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,ZM_V4L2,ZM_HAS_V4L2,g' ${WRKSRC}//web/skins/classic/views/monitorprobe.php

pre-build:
	${CP} ${FILESDIR}/videodev.h ${WRKSRC}/src
	${CP} ${FILESDIR}/zm_fbsd_camera.cpp ${WRKSRC}/src
	${TOUCH} ${WRKSRC}/src/zm_fbsd_camera.h

post-install:
	@if [ ! -f ${PREFIX}/etc/zm.conf ]; then \
		${CP} -p ${PREFIX}/etc/zm.conf.sample ${PREFIX}/etc/zm.conf  ; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS   ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING   ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/INSTALL   ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEWS      ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README    ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO      ${DOCSDIR}
	${INSTALL_MAN} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.endif
	${CAT} ${FILESDIR}/README.FreeBSD

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-scripts_ZoneMinder_lib_ZoneMinder_Memory.pm.in
.endif

.include <bsd.port.post.mk>
