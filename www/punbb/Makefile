# New ports collection makefile for:	punbb
# Date created:		2006-08-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	punbb
PORTVERSION=	1.2.22
CATEGORIES=	www
MASTER_SITES=	http://punbb.informer.com/download/ \
		http://punbb.informer.com/download/plugins/:plugins \
		http://punbb.informer.com/download/lang_packs-1.2/:lang \
		http://freebsd.csie.nctu.edu.tw/~gslin/files/punbb-${PORTVERSION}/:lang
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LANGFILES:S/$/:lang/} \
		${PLUGINS:S/$/:plugins/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gslin@gslin.org
COMMENT=	A fast and lightweight PHP-powered discussion board

BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

PORTEXAMPLES=	12_to_1222_update.php example_config.php \
		turn_off_maintenance_mode.php
SUB_FILES=	pkg-message

NO_BUILD=	yes
USE_PHP=	yes
USE_BZIP2=	yes

OPTIONS=	LANGUAGE_PACK "Install language packs" on \
		EXTRAS "Install all plugins available" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LANGUAGE_PACK)
LANGFILES+=	Arabic.zip \
		Bangla_UTF8.zip \
		Belarusian.zip \
		Bosnian.zip \
		Brazilian_Portuguese.zip \
		Bulgarian.zip \
		Bulgarian_UTF8.zip \
		Catalan.zip \
		Czech.zip \
		Czech_UTF8.zip \
		Danish.zip \
		Dutch.zip \
		Estonian.zip \
		Farsi.zip \
		Finnish.zip \
		French.zip \
		Galician.zip \
		German.zip \
		Greek.zip \
		Hebrew.zip \
		Hindi.zip \
		Hrvatski.zip \
		Hungarian.zip \
		Icelandic.zip \
		Indonesian.zip \
		Italian.zip \
		Japanese.zip \
		Korean.zip \
		Kurdish.zip \
		Latvian.zip \
		Lithuanian.zip \
		Norwegian.zip \
		Polish.zip \
		Polish_UTF8.zip \
		Portuguese.zip \
		Romanian.zip \
		Russian.zip \
		Serbian.zip \
		Simplified_Chinese.zip \
		Slovak.zip \
		Slovak_UTF8.zip \
		Slovenian.zip \
		Spanish.zip \
		Swedish.zip \
		Traditional_Chinese.zip \
		Turkish.zip \
		Ukrainian.zip \
		Ukrainian_UTF8.zip \
		Urdu.zip \
		Vietnamese.zip
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

.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	cd ${WRKSRC}/extras && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
