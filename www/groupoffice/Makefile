PORTNAME=	groupoffice
DISTVERSIONPREFIX=	com-
DISTVERSION=	25.0.36
CATEGORIES=	www
MASTER_SITES=	SF/group-office/${DISTVERSION:R}
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Modular web application framework for office
WWW=		https://www.group-office.com/

LICENSE=	AGPLv3 PERSONAL
LICENSE_COMB=	multi
LICENSE_NAME_PERSONAL=	Personal use
LICENSE_TEXT_PERSONAL=	Free for personal use only
LICENSE_PERMS_PERSONAL=	auto-accept

USES=		mysql shebangfix php:web python

NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	ctype curl dom exif fileinfo filter intl mbstring \
		mysqli pdo pdo_mysql phar posix session \
		simplexml soap sysvshm sysvsem tokenizer xml xmlreader \
		xmlwriter zip zlib
SHEBANG_FILES=	groupoffice \
		groupofficecli.php \
		vendor/sabre/dav/bin/naturalselection \
		vendor/bin/../sabre/dav/bin/naturalselection

WWWDIR?=	${PREFIX}/www/${PORTNAME}${DISTVERSION:R:R}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	APCU IMAP GD CALENDAR WBXML
OPTIONS_DEFAULT=APCU IMAP GD CALENDAR
APCU_DESC=	Local data caching using APCu (recommended)
APCU_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}APCu>0:devel/pecl-APCu@${PHP_FLAVOR}
CALENDAR_DESC=	Calendar holiday support
IMAP_DESC=	IMAP support
GD_DESC=	Gallery support (GD)
WBXML_DESC=	Synchronization Support

CALENDAR_USE=		PHP=calendar
GD_USE=			PHP=gd
IMAP_USE=		PHP=iconv imap
WBXML_LIB_DEPENDS=	libwbxml2.so:textproc/libwbxml

post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/go/base/Config.php
	@${REINPLACE_CMD} 's|/etc/groupoffice|${PREFIX}&|g' \
		${WRKSRC}/go/modules/community/serverclient/model/HttpClient.php \
		${WRKSRC}/install/configfile.php \
		${WRKSRC}/modules/site/index.php

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${TOUCH} ${STAGEDIR}${WWWDIR}/config.php.sample

.include <bsd.port.mk>
