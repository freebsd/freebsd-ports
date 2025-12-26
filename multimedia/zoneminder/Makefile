PORTNAME=	zoneminder
DISTVERSION=	1.36.37
CATEGORIES=	multimedia
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	bsd@abinet.ru
COMMENT=	Complete security camera solution, fully web based with image analysis
WWW=		https://www.zoneminder.com/

LICENSE=	GPLv2

ZM_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		${DBD_MYSQL} \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Test-LWP-UserAgent>=0:www/p5-Test-LWP-UserAgent \
		p5-Sys-Mmap>=0:devel/p5-Sys-Mmap \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Sys-CPU>=0:devel/p5-Sys-CPU \
		p5-Sys-MemInfo>=0:devel/p5-Sys-MemInfo \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-SOAP-WSDL>=0:devel/p5-SOAP-WSDL \
		p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-IO-Socket-Multicast>=0:net/p5-IO-Socket-Multicast \
		p5-Number-Bytes-Human>=0:devel/p5-Number-Bytes-Human \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS
BUILD_DEPENDS=	${ZM_DEPENDS}
LIB_DEPENDS=	libx264.so:multimedia/libx264 \
		libmp4v2.so:multimedia/mp4v2 \
		libgcrypt.so:security/libgcrypt \
		libavcodec.so:multimedia/ffmpeg
RUN_DEPENDS=	${ZM_DEPENDS} \
		p5-Device-SerialPort>=0:comms/p5-Device-SerialPort \
		p5-Crypt-Eksblowfish>=0:security/p5-Crypt-Eksblowfish \
		p5-Bytes-Random-Secure>=0:security/p5-Bytes-Random-Secure \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		zip:archivers/zip \
		${PECL_PKGNAMEPREFIX}APCu>0:devel/pecl-APCu@${PHP_FLAVOR}

USES=		cmake:insource,noninja cpe jpeg mysql perl5 php:flavors shebangfix ssl sudo
USE_GITHUB=	yes
GH_TUPLE=	FriendsOfCake:crud:1429237:crud/web/api/app/Plugin/Crud \
		ZoneMinder:CakePHP-Enum-Behavior:ea90c0c:crud_plugin/web/api/app/Plugin/CakePHP-Enum-Behavior \
		ZoneMinder:RtspServer:eab3285:rtsp_server/dep/RtspServer
USE_PHP=	ctype gd intl opcache pdo_mysql session sockets sysvsem
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	scripts/zmaudit.pl.in \
		scripts/zmcamtool.pl.in \
		scripts/zmcontrol.pl.in \
		scripts/zmdc.pl.in \
		scripts/zmfilter.pl.in \
		scripts/zmpkg.pl.in \
		scripts/zmstats.pl.in \
		scripts/zmtelemetry.pl.in \
		scripts/zmtrack.pl.in \
		scripts/zmtrigger.pl.in \
		scripts/zmupdate.pl.in \
		scripts/zmvideo.pl.in \
		scripts/zmwatch.pl.in \
		scripts/zmx10.pl.in \
		scripts/zmonvif-probe.pl.in \
		scripts/zmrecover.pl.in

CMAKE_ARGS+=	-DZM_PERL_MM_PARMS=INSTALLDIRS=site \
		-DZM_CONFIG_DIR=${PREFIX}/etc \
		-DZM_CONFIG_SUBDIR=${PREFIX}/etc/zoneminder \
		-DZM_WEBDIR=${WWWDIR} \
		-DZM_CGIDIR=${WWWDIR}/cgi-bin \
		-DZM_CONTENTDIR=/var/db/zoneminder \
		-DZM_MANPAGE_DEST_PREFIX=${PREFIX}/share/man \
		-DHAVE_SENDFILE=0 \
		-DZM_NO_CURL=ON \
		-DZM_NO_LIBVLC=ON \
		-DPCRE_LIBRARIES=0 \
		-DZM_PATH_MAP=/tmp \
		-DGNUTLS_LIBRARIES=0 \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=		NLS V4L
OPTIONS_SUB=		yes
NLS_USES=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-D__SKIP_GNU
.endif

post-patch:
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/version ${WRKSRC}/version.txt
	@${REINPLACE_CMD} -i .c++20 's/"version/&.txt/' \
		${WRKSRC}/CMakeLists.txt

pre-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/temp \
		 ${STAGEDIR}${WWWDIR}/api/app/tmp \
		 ${STAGEDIR}/var/cache/zoneminder \
		 ${STAGEDIR}/var/db/zoneminder/events \
		 ${STAGEDIR}/var/log/zm \
		 ${STAGEDIR}/var/run/zm \
		 ${STAGEDIR}/var/tmp/zm

post-install: # zmsystemctl.pl is only for systemd-based systems
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} \
			bin/zmsystemctl.pl \
			share/man/man8/zmsystemctl.pl.8.gz

.include <bsd.port.post.mk>
