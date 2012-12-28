# New ports collection makefile for:	multimedia/zoneminder
# Date created:				2011-04-08
# Whom:					bsam, based on ports by achix (1.23 & local camera stuff),
#					Richard Lee and Electric Messiah
# $FreeBSD$
#

PORTNAME=	zoneminder
PORTVERSION=	1.25.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www2.zoneminder.com/downloads/ \
		http://www.zoneminder.com/downloads/
DISTNAME=	ZoneMinder-${PORTVERSION}

MAINTAINER=	pakhom706@gmail.com
COMMENT=	Complete security camera solution, fully web based with image analysis

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/sudo:${PORTSDIR}/security/sudo
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		netpbm.1:${PORTSDIR}/graphics/netpbm \
		pcre.3:${PORTSDIR}/devel/pcre \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg
BUILD_DEPENDS=	${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php5-extensions \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
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

PORTDOCS=	AUTHORS \
		COPYING \
		ChangeLog \
		INSTALL \
		NEWS \
		README \
		README.FreeBSD \
		TODO

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
		ZoneMinder::ConfigAdmin.3 \
		ZoneMinder::ConfigData.3 \
		ZoneMinder::Logger.3

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-scripts_ZoneMinder_lib_ZoneMinder_Memory.pm.in
.endif

.if ${OSVERSION} < 900000
BROKEN=	does not compile on 7.X and 8.X
.endif

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
	${CP} ${FILESDIR}/README.FreeBSD ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif
	${CAT} ${FILESDIR}/README.FreeBSD

.include <bsd.port.post.mk>
