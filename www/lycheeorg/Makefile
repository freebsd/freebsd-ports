PORTNAME=	lycheeorg
DISTVERSIONPREFIX=	v
DISTVERSION=	7.7.5
CATEGORIES=	www
MASTER_SITES=	https://github.com/LycheeOrg/Lychee/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	Lychee

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Great looking and easy-to-use photo-management-system
WWW=		https://lycheeorg.dev

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php zip
USE_PHP=	bcmath ctype dom exif fileinfo filter gd json mbstring mysqli \
		opcache openssl pcre pdo pdo_mysql pdo_pgsql pdo_sqlite pgsql \
		phar session simplexml sodium sqlite3 tokenizer xml xmlwriter \
		zlib

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	lychee.cron nginx.conf pkg-message

OPTIONS_DEFINE=		EXAMPLES EXIFTOOL FFMPEG IMAGEMAGICK LDAP MEMCACHED \
			REDIS
OPTIONS_DEFAULT=	EXIFTOOL FFMPEG IMAGEMAGICK MEMCACHED REDIS

EXIFTOOL_DESC=		Support for better handling of EXIF metadata
FFMPEG_DESC=		Support for generating video thumbnails
IMAGEMAGICK_DESC=	Support for generating better thumbnails
MEMCACHED_DESC=		Memcached key-value store database support

EXIFTOOL_RUN_DEPENDS=		p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool
FFMPEG_RUN_DEPENDS=		ffmpeg>=0:multimedia/ffmpeg
IMAGEMAGICK_RUN_DEPENDS=	${PHP_PKGNAMEPREFIX}pecl-imagick>=0:graphics/pecl-imagick@${PHP_FLAVOR}
IMAGEMAGICK_VARS=		IGNORE_WITH_PHP=86
LDAP_USE=			PHP=ldap
MEMCACHED_RUN_DEPENDS=		${PHP_PKGNAMEPREFIX}pecl-memcached>=0:databases/pecl-memcached@${PHP_FLAVOR}
REDIS_RUN_DEPENDS=		${PHP_PKGNAMEPREFIX}pecl-redis>=0:databases/pecl-redis@${PHP_FLAVOR}

LYCHEEORG_WRITABLE_DIRS=	database storage/framework \
				storage/framework/views storage/framework/cache \
				storage/framework/sessions storage/logs \
				storage/tmp/extract storage/tmp/jobs \
				storage/tmp/uploads bootstrap/cache public/dist \
				public/uploads storage/debugbar

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

post-install:
.for d in ${LYCHEEORG_WRITABLE_DIRS}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${d}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_DATA} ${WRKDIR}/lychee.cron ${STAGEDIR}${PREFIX}/etc/cron.d/lychee

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/nginx.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
