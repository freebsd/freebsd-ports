# $FreeBSD$

PORTNAME=	zoneminder
PORTVERSION=	1.30.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	multimedia

MAINTAINER=	bsd@abinet.ru
COMMENT=	Complete security camera solution, fully web based with image analysis

LICENSE=	GPLv2

ZM_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Test-LWP-UserAgent>=0:www/p5-Test-LWP-UserAgent \
		p5-Sys-Mmap>=0:devel/p5-Sys-Mmap \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Sys-CPU>=0:devel/p5-Sys-Cpu \
		p5-Sys-MemInfo>=0:devel/p5-Sys-MemInfo \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-SOAP-WSDL>=0:devel/p5-SOAP-WSDL \
		p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-IO-Socket-Multicast>=0:net/p5-IO-Socket-Multicast \
		ffmpeg:multimedia/ffmpeg
BUILD_DEPENDS=	${ZM_DEPENDS}
RUN_DEPENDS=	${ZM_DEPENDS} \
		sudo:security/sudo \
		zip:archivers/zip

USE_GITHUB=	yes
GH_PROJECT=	ZoneMinder
GH_TUPLE=	FriendsOfCake:crud:c3976f1:crud

USES=		cmake jpeg mysql perl5 php shebangfix ssl
USE_RC_SUBR=	zoneminder
USE_PHP=	json pdo_mysql session gd sockets

ONLY_FOR_ARCHS=	amd64 i386

OPTIONS_DEFINE=	NLS V4L DOCS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
OPTIONS_DEFAULT=	NLS

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

SHEBANG_FILES=	scripts/zmaudit.pl.in \
		scripts/zmcamtool.pl.in \
		scripts/zmcontrol.pl.in \
		scripts/zmdc.pl.in \
		scripts/zmfilter.pl.in \
		scripts/zmpkg.pl.in \
		scripts/zmtelemetry.pl.in \
		scripts/zmtrack.pl.in \
		scripts/zmtrigger.pl.in \
		scripts/zmupdate.pl.in \
		scripts/zmvideo.pl.in \
		scripts/zmwatch.pl.in \
		scripts/zmx10.pl.in \
		onvif/scripts/zmonvif-probe.pl

PORTDOCS=	AUTHORS BUGS ChangeLog INSTALL NEWS README.FreeBSD TODO

CMAKE_ARGS+=	-DZM_PERL_MM_PARMS=INSTALLDIRS=site \
		-DZM_CONFIG_DIR=${PREFIX}/etc \
		-DZM_WEBDIR=${WWWDIR} \
		-DZM_CGIDIR=${WWWDIR}/cgi-bin \
		-DZM_CONTENTDIR=${WWWDIR} \
		-DHAVE_SENDFILE=0 \
		-DZM_NO_CURL=ON \
		-DZM_NO_LIBVLC=ON \
		-DPCRE_LIBRARIES=0 \
		-DGNUTLS_LIBRARIES=0 \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	${CP} -R ${WRKSRC_crud}/* ${WRKSRC}/web/api/app/Plugin/Crud
	${CP} ${FILESDIR}/README.FreeBSD ${WRKSRC}
	${CP} ${FILESDIR}/README.FreeBSD ${PKGMESSAGE}
	${REINPLACE_CMD} -e 's|/dev/shm|/tmp|g' ${WRKSRC}/scripts/ZoneMinder/lib/ZoneMinder/ConfigData.pm.in
	${REINPLACE_CMD} -e 's|E_ALL|E_ALL^E_NOTICE|g' ${WRKSRC}/web/index.php

pre-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/images
	${MKDIR} ${STAGEDIR}${WWWDIR}/events
	${MKDIR} ${STAGEDIR}${WWWDIR}/temp
	${MKDIR} ${STAGEDIR}${WWWDIR}/api/app/tmp
	${MKDIR} ${STAGEDIR}/var/run/zm
	${MKDIR} ${STAGEDIR}/var/tmp/zm

post-install:
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/zm.conf ${STAGEDIR}${PREFIX}/etc/zm.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
