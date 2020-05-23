# Created by: Goran Lowkrantz <glz@hidden-powers.com>
# $FreeBSD$

PORTNAME=	piwigo
DISTVERSION=	2.10.2
CATEGORIES=	www
MASTER_SITES=	https://piwigo.org/download/dlcounter.php?code=${PORTVERSION}&/

MAINTAINER=	tremere@cainites.net
COMMENT=	PHP based Web Gallery

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		cpe php:web zip
USE_PHP=	calendar ctype dom exif filter gd gettext hash iconv json \
		mbstring mcrypt mysqli openssl pcre pdf pdo posix session \
		simplexml sockets spl tokenizer xml xmlreader xmlwriter zlib

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-deinstall pkg-message
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

OPTIONS_DEFINE=		DOCS EXAMPLES IMAGICK X11
OPTIONS_DEFAULT=	IMAGICK

IMAGICK_DESC=	${IMAGEMAGICK_DESC}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:graphics/ImageMagick6
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:graphics/ImageMagick6-nox11
.endif
.endif

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

.include <bsd.port.post.mk>
