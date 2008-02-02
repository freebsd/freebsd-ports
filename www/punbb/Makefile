# New ports collection makefile for:	punbb
# Date created:		2006-08-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	punbb
PORTVERSION=	1.2.16
CATEGORIES=	www
MASTER_SITES=	http://punbb.org/download/ \
		http://punbb.org/download/plugins/:plugins \
		http://mirror.ordo.dk/punbb.org/ \
		http://punbb.mirrors.typhon.net/ \
		http://punbb.4any.org/ \
		http://freebsd.csie.nctu.edu.tw/~gslin/files/punbb-${PORTVERSION}/:lang
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LANGFILES:S/$/:lang/} \
		${PLUGINS:S/$/:plugins/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gslin@gslin.org
COMMENT=	A fast and lightweight PHP-powered discussion board

BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

PORTDOCS=	about.html dev.html faq.html \
		index.html install.html
PORTEXAMPLES=	12_to_1216_update.php example_config.php \
		turn_off_maintenance_mode.php
SUB_FILES=	pkg-message

NO_BUILD=	yes
USE_PHP=	yes
USE_BZIP2=	yes

OPTIONS=	LANGUAGE_PACK "Install language packs" on \
		EXTRAS "Install all plugins available" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LANGUAGE_PACK)
LANGFILES+=	lang_packs-${PORTVERSION}/Arabic.zip \
		lang_packs-${PORTVERSION}/Bangla_UTF8.zip \
		lang_packs-${PORTVERSION}/Belarusian.zip \
		lang_packs-${PORTVERSION}/Bosnian.zip \
		lang_packs-${PORTVERSION}/Brazilian_Portuguese.zip \
		lang_packs-${PORTVERSION}/Bulgarian.zip \
		lang_packs-${PORTVERSION}/Bulgarian_UTF8.zip \
		lang_packs-${PORTVERSION}/Catalan.zip \
		lang_packs-${PORTVERSION}/Czech.zip \
		lang_packs-${PORTVERSION}/Czech_UTF8.zip \
		lang_packs-${PORTVERSION}/Danish.zip \
		lang_packs-${PORTVERSION}/Dutch.zip \
		lang_packs-${PORTVERSION}/Estonian.zip \
		lang_packs-${PORTVERSION}/Farsi.zip \
		lang_packs-${PORTVERSION}/Finnish.zip \
		lang_packs-${PORTVERSION}/French.zip \
		lang_packs-${PORTVERSION}/Galician.zip \
		lang_packs-${PORTVERSION}/German.zip \
		lang_packs-${PORTVERSION}/Greek.zip \
		lang_packs-${PORTVERSION}/Hebrew.zip \
		lang_packs-${PORTVERSION}/Hindi.zip \
		lang_packs-${PORTVERSION}/Hrvatski.zip \
		lang_packs-${PORTVERSION}/Hungarian.zip \
		lang_packs-${PORTVERSION}/Icelandic.zip \
		lang_packs-${PORTVERSION}/Indonesian.zip \
		lang_packs-${PORTVERSION}/Italian.zip \
		lang_packs-${PORTVERSION}/Japanese.zip \
		lang_packs-${PORTVERSION}/Korean.zip \
		lang_packs-${PORTVERSION}/Kurdish.zip \
		lang_packs-${PORTVERSION}/Latvian.zip \
		lang_packs-${PORTVERSION}/Lithuanian.zip \
		lang_packs-${PORTVERSION}/Norwegian.zip \
		lang_packs-${PORTVERSION}/Polish.zip \
		lang_packs-${PORTVERSION}/Polish_UTF8.zip \
		lang_packs-${PORTVERSION}/Portuguese.zip \
		lang_packs-${PORTVERSION}/Romanian.zip \
		lang_packs-${PORTVERSION}/Russian.zip \
		lang_packs-${PORTVERSION}/Serbian.zip \
		lang_packs-${PORTVERSION}/Simplified_Chinese.zip \
		lang_packs-${PORTVERSION}/Slovak.zip \
		lang_packs-${PORTVERSION}/Slovak_UTF8.zip \
		lang_packs-${PORTVERSION}/Slovenian.zip \
		lang_packs-${PORTVERSION}/Spanish.zip \
		lang_packs-${PORTVERSION}/Swedish.zip \
		lang_packs-${PORTVERSION}/Traditional_Chinese.zip \
		lang_packs-${PORTVERSION}/Turkish.zip \
		lang_packs-${PORTVERSION}/Ukrainian.zip \
		lang_packs-${PORTVERSION}/Ukrainian_UTF8.zip \
		lang_packs-${PORTVERSION}/Urdu.zip \
		lang_packs-${PORTVERSION}/Vietnamese.zip
PLIST_SUB+=	LANGUAGE_PACK=""
.else
PLIST_SUB+=	LANGUAGE_PACK="@comment "
.endif

.if defined(WITH_EXTRAS)
PLUGINS+=	AP_User_Merge.zip \
		AP_Author_Update.zip \
		AP_PunBB_Shell.zip \
		AP_Backup.zip \
		AP_Forum_cleanup.zip \
		AP_Clear_Cache.zip \
		AP_Merge_Forums.zip \
		AMP_Global_topic.zip \
		AP_Languages_and_styles.zip \
		AP_Broadcast_Email.zip \
		AP_DB_management.zip \
		AP_User_management.zip \
		AP_News_Generator.zip \
		AP_Version_Changer.zip
PLIST_SUB+=	PLUGINS=""
.else
PLIST_SUB+=	PLUGINS="@comment "
.endif

do-install:
	@cd ${WRKSRC}/upload && ${COPYTREE_SHARE} . ${WWWDIR}

.for i in ${LANGFILES}
	${UNZIP_CMD} -o ${DISTDIR}/${i} -d ${WWWDIR}/lang
.endfor

.for i in ${PLUGINS}
	${UNZIP_CMD} -o ${DISTDIR}/${i} -d ${WWWDIR}/plugins
.endfor

.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	cd ${WRKSRC}/extras && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
