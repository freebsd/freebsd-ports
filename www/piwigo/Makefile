# Created by: Goran Lowkrantz <glz@hidden-powers.com>
# $FreeBSD$

PORTNAME=	piwigo
PORTVERSION=	2.5.1
CATEGORIES=	www
MASTER_SITES=	http://piwigo.org/download/dlcounter.php?code=${PORTVERSION}&/ \
		SF/${PORTNAME}/Piwigo/${PORTVERSION}

MAINTAINER=	glz@hidden-powers.com
COMMENT=	PHP based Web Gallery

NO_BUILD=	yes
USE_PHP=	calendar ctype dom exif filter gd gettext hash iconv json \
		mbstring mcrypt mhash mysql mysqli openssl pcre pdf pdo posix session \
		simplexml sockets spl tokenizer xml xmlreader xmlwriter zlib
USES=		zip
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-install pkg-deinstall pkg-message
SUB_LIST+=	CP="${CP}" \
		MKDIR="${MKDIR}" \
		CHOWN="${CHOWN}" \
		TOUCH="${TOUCH}" \
		WWWOWN="${WWWOWN}" \
		WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	IMAGICK
OPTIONS_DEFAULT=IMAGICK
IMAGICK_DESC=	${IMAGEMAGICK_DESC}

PORTDOCS=	COPYING README_en.txt README_fr.txt

PLIST_SUB+=	WWWOWN="${WWWOWN}" \
		WWWGRP="${WWWGRP}" \
		CHOWN="${CHOWN}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif
.endif

post-extract:
	@${CHMOD} -R o-w ${WRKSRC}

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/tools/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif

	@${RM} -fr ${WRKSRC}/doc/ ${WRKSRC}/tools/ ${WRKSRC}/_data/ ${WRKSRC}/upload/
	@${MV} ${WRKSRC}/local/ ${WRKSRC}/local.sample/
	@cd ${WRKSRC}/ && ${COPYTREE_INSTALL} . ${WWWDIR}

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

# Own version with our owners and we also have to protect if
# galleries is read-only.
COPYTREE_INSTALL=	${SH} -c '(${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$0 && \
		${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
		2>&1) && \
		${FIND} -d $$0 $$2 -type d -exec ${CHMOD} 755 $$1/{} \; && \
		${FIND} -d $$0 $$2 -type f -exec ${CHMOD} ${SHAREMODE} $$1/{} \;' --

.include <bsd.port.post.mk>
