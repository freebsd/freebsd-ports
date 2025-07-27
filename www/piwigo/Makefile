PORTNAME=	piwigo
DISTVERSION=	15.6.0
PORTREVISION=	0
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
CATEGORIES=	www
MASTER_SITES=	https://piwigo.org/download/dlcounter.php?code=${PORTVERSION}&/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	PHP based Web Gallery
WWW=		https://piwigo.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		cpe php:web,flavors zip
# php hash/json/openssl/pcre/spl extension is required but it's statically linked in default php
USE_PHP=	ctype dom exif filter gd iconv json mbstring mysqli \
		pdo session simplexml sodium tokenizer \
		xml zip zlib
# sodium is needed for randomisation stuff (prefferred option),
# 	could be replaced by mcrypt
# zip is used by an optional plugin

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST+=	CHOWN="${CHOWN}" \
		CP="${CP}" \
		MKDIR="${MKDIR}" \
		TOUCH="${TOUCH}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB+=	CHOWN="${CHOWN}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"
PORTDOCS=	README_ca.txt README_en.txt README_fr.txt

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_GROUP=		OPT
OPTIONS_GROUP_OPT=	EXIFTOOL FFMPEG IMAGICK MEDIAINFO

EXIFTOOL_DESC=	exiftool support (for plugins)
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MEDIAINFO_DESC=	mediainfo support (for plugins)
OPT_DESC=	Optional dependencies

EXIFTOOL_RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
IMAGICK_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}imagick>=2.2.2:graphics/pecl-imagick@${PHP_FLAVOR}
MEDIAINFO_RUN_DEPENDS=	mediainfo:multimedia/mediainfo

.include <bsd.port.pre.mk>

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

pre-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC}/tools/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

do-install:
	@cd ${WRKSRC}/doc/ && ${RM} ${PORTDOCS}
	@${RM} -r ${WRKSRC}/tools ${WRKSRC}/_data/dummy.txt
	@${INSTALL} -d ${STAGEDIR}${WWWDIR}
	@${TAR} -C ${WRKSRC} -cf - . | \
	${TAR} --unlink -C ${STAGEDIR}${WWWDIR} -xf -

gen-plist:
	${ECHO} '@dir(%%WWWOWN%%,%%WWWGRP%%,750) %%WWWDIR%%/language' > ${PLIST}.new
	${ECHO} '@dir(%%WWWOWN%%,%%WWWGRP%%,750) %%WWWDIR%%/plugins' >> ${PLIST}.new
	${ECHO} '@dir(%%WWWOWN%%,%%WWWGRP%%,750) %%WWWDIR%%/themes' >> ${PLIST}.new
	${FIND} ${STAGEDIR}${PREFIX} -type f -o -type l | \
	    ${SED} -e "s:${STAGEDIR}${PREFIX}/::g ; \
	        s:www/piwigo/language:@(%%WWWOWN%%,%%WWWGRP%%,750) %%WWWDIR%%/language:g ; \
		s:www/piwigo/plugins:@(%%WWWOWN%%,%%WWWGRP%%,750) %%WWWDIR%%/plugins:g ; \
		s:www/piwigo/themes:@(%%WWWOWN%%,%%WWWGRP%%,750) %%WWWDIR%%/themes:g ; \
	    	s:www/piwigo:%%WWWDIR%%:g ; \
		s:share/examples/piwigo:%%PORTEXAMPLES%%%%EXAMPLESDIR%%:g ;" |  \
	    ${GREP} -v -E '^share/(doc|licenses)/' | ${SORT} >> ${PLIST}.new
	${ECHO} '@dir(%%WWWOWN%%,%%WWWGRP%%,777) %%WWWDIR%%/_data' >> ${PLIST}.new
	${ECHO} '@dir(%%WWWOWN%%,%%WWWGRP%%,750) %%WWWDIR%%/upload' >> ${PLIST}.new

.include <bsd.port.post.mk>
