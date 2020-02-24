# $FreeBSD$

PORTNAME=	zoneminder
PORTVERSION=	1.34.3
CATEGORIES=	multimedia

MAINTAINER=	bsd@abinet.ru
COMMENT=	Complete security camera solution, fully web based with image analysis

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64 i386

ZM_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
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
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		ffmpeg:multimedia/ffmpeg
BUILD_DEPENDS=	${ZM_DEPENDS}
LIB_DEPENDS=	libx264.so:multimedia/libx264 \
		libmp4v2.so:multimedia/mp4v2 \
		libgcrypt.so:security/libgcrypt
RUN_DEPENDS=	${ZM_DEPENDS} \
		sudo:security/sudo \
		p5-Device-SerialPort>=0:comms/p5-Device-SerialPort \
		p5-Crypt-Eksblowfish>=0:security/p5-Crypt-Eksblowfish \
		p5-Data-Entropy>=0:security/p5-Data-Entropy \
		zip:archivers/zip

USES=		cmake:insource,noninja jpeg mysql perl5 php shebangfix ssl
USE_GITHUB=	yes
GH_PROJECT=	zoneminder
GH_TUPLE=	zoneminder:crud:0bd63fb:crud \
		zoneminder:CakePHP-Enum-Behavior:ea90c0c:crud_plugin
USE_RC_SUBR=	zoneminder
USE_PHP=	json pdo_mysql session gd sockets ctype opcache openssl hash

OPTIONS_DEFINE=	NLS V4L DOCS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
V4L_BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

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

PORTDOCS=	README.FreeBSD

CMAKE_ARGS+=	-DZM_PERL_MM_PARMS=INSTALLDIRS=site \
		-DZM_CONFIG_DIR=${PREFIX}/etc \
		-DZM_CONFIG_SUBDIR=${PREFIX}/etc/zoneminder \
		-DZM_WEBDIR=${WWWDIR} \
		-DZM_CGIDIR=${WWWDIR}/cgi-bin \
		-DZM_CONTENTDIR=/var/db/zoneminder \
		-DZM_MANPAGE_DEST_PREFIX=${PREFIX}/man \
		-DHAVE_SENDFILE=0 \
		-DZM_NO_CURL=ON \
		-DZM_NO_LIBVLC=ON \
		-DPCRE_LIBRARIES=0 \
		-DZM_PATH_MAP=/tmp \
		-DGNUTLS_LIBRARIES=0 \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1200000
    EXTRA_PATCHES=	${PATCHDIR}/extra-patch-CMakeLists.txt
.endif

RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/apcu.so:devel/pecl-APCu@${PHP_FLAVOR}

PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	${CP} -R ${WRKSRC_crud}/* ${WRKSRC}/web/api/app/Plugin/Crud
	${CP} -R ${WRKSRC_crud_plugin}/* ${WRKSRC}/web/api/app/Plugin/CakePHP-Enum-Behavior
	${CP} ${FILESDIR}/README.FreeBSD ${WRKSRC}
	${CP} ${FILESDIR}/README.FreeBSD ${PKGMESSAGE}
	${REINPLACE_CMD} -e 's|/dev/shm|/tmp|g' ${WRKSRC}/scripts/ZoneMinder/lib/ZoneMinder/ConfigData.pm.in

post-patch:
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/version ${WRKSRC}/version.txt
	@${REINPLACE_CMD} -i .c++20 's/"version/&.txt/' \
		${WRKSRC}/CMakeLists.txt

pre-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/temp
	${MKDIR} ${STAGEDIR}${WWWDIR}/api/app/tmp
	${MKDIR} ${STAGEDIR}/var/cache/zoneminder
	${MKDIR} ${STAGEDIR}/var/cache/zoneminder/events
	${MKDIR} ${STAGEDIR}/var/cache/zoneminder/images
	${MKDIR} ${STAGEDIR}/var/db/zoneminder
	${MKDIR} ${STAGEDIR}/var/run/zm
	${MKDIR} ${STAGEDIR}/var/tmp/zm

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
