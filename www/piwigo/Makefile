# Created by: Goran Lowkrantz <glz@hidden-powers.com>
# $FreeBSD$

PORTNAME=	piwigo
PORTVERSION=	2.6.3
CATEGORIES=	www
MASTER_SITES=	http://piwigo.org/download/dlcounter.php?code=${PORTVERSION}&/ \
		SF/${PORTNAME}/Piwigo/${PORTVERSION}

MAINTAINER=	glz@hidden-powers.com
COMMENT=	PHP based Web Gallery

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

NO_BUILD=	yes
USE_PHP=	calendar ctype dom exif filter gd gettext hash iconv json \
		mbstring mcrypt mhash mysql mysqli openssl pcre pdf pdo posix \
		session simplexml sockets spl tokenizer xml xmlreader \
		xmlwriter zlib
USES=		zip
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST+=	CP="${CP}" \
		MKDIR="${MKDIR}" \
		CHOWN="${CHOWN}" \
		TOUCH="${TOUCH}" \
		WWWOWN="${WWWOWN}" \
		WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	IMAGICK X11 DOCS EXAMPLES
OPTIONS_DEFAULT=IMAGICK
IMAGICK_DESC=	${IMAGEMAGICK_DESC}

PORTDOCS=	README_ca.txt README_en.txt README_fr.txt

PLIST_SUB+=	WWWOWN="${WWWOWN}" \
		WWWGRP="${WWWGRP}" \
		CHOWN="${CHOWN}"
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif
.endif

post-extract:
	@${MV} ${WRKSRC}/local ${WRKSRC}/local.sample
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}
	@${FIND} -d ${WRKSRC} -type d -exec ${CHMOD} 755 {} \;
	@${FIND} -d ${WRKSRC} -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC}/tools/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/
.endif
	@cd ${WRKSRC}/doc/ && ${RM} ${PORTDOCS}
	@${RM} -fr ${WRKSRC}/tools ${WRKSRC}/_data ${WRKSRC}/upload
	@${INSTALL} -d ${STAGEDIR}${WWWDIR}
	@${TAR} -C ${WRKSRC} -cf - . | \
			${TAR} --unlink -C ${STAGEDIR}${WWWDIR} -xf -

post-install:
	@if [ ! -e ${STAGEDIR}${WWWDIR}/local ]; then \
		${INSTALL} -d ${STAGEDIR}${WWWDIR}/local/ ; \
		${CP} -a ${STAGEDIR}${WWWDIR}/local.sample/ \
			${STAGEDIR}${WWWDIR}/local/ ; \
	fi;
	@${CHOWN} -fR ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}/plugins
	@if [ ! -e ${STAGEDIR}${WWWDIR}/upload ]; then \
		${INSTALL} -d ${STAGEDIR}${WWWDIR}/upload/ ; \
		${CHMOD} 750 ${STAGEDIR}${WWWDIR}/upload ; \
		${CHOWN} ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}/upload ; \
	fi
	@if [ ! -e ${STAGEDIR}${WWWDIR}/_data ]; then \
		${INSTALL} -d ${STAGEDIR}${WWWDIR}/_data/ ; \
		${CHMOD} 777 ${STAGEDIR}${WWWDIR}/_data ; \
		${CHOWN} ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}/_data ; \
	fi

.include <bsd.port.post.mk>
