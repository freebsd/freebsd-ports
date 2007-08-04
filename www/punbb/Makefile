# New ports collection makefile for:	punbb
# Date created:		2006-08-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	punbb
PORTVERSION=	1.2.15
CATEGORIES=	www
MASTER_SITES=	http://www.punbb.org/download/ \
		http://mirror.ordo.dk/punbb.org/ \
		http://punbb.mirrors.typhon.net/ \
		http://punbb.4any.org/ \
		http://freebsd.csie.nctu.edu.tw/~gslin/files/punbb-${PORTVERSION}/:lang
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LANGFILES:S/$/:lang/}
EXTRACT_ONLY=	# none

MAINTAINER=	gslin@gslin.org
COMMENT=	A fast and lightweight PHP-powered discussion board

BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes
PUNBBDIR?=	${PREFIX}/www/punbb
USE_PHP=	yes
USE_ZIP=	yes

OPTIONS=	LANGUAGE_PACK "Install language packs" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LANGUAGE_PACK)
LANGFILES+=	lang_packs-${PORTVERSION}/Arabic.zip \
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

do-install:
	${MKDIR} ${PUNBBDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/punbb-${DISTVERSION}.zip -d ${PUNBBDIR}
.for i in ${LANGFILES}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${i} -d \
		${PUNBBDIR}/upload/lang
.endfor
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PUNBBDIR}

.include <bsd.port.post.mk>
