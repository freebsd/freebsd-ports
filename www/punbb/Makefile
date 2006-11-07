# New ports collection makefile for:	punbb
# Date created:		2006-08-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	punbb
PORTVERSION=	1.2.14
CATEGORIES=	www
MASTER_SITES=	http://www.punbb.org/download/ \
		http://mirror.ordo.dk/punbb.org/ \
		http://punbb.mirrors.typhon.net/ \
		http://punbb.4any.org/ \
		http://freebsd.csie.nctu.edu.tw/~gslin/files/punbb-1.2.14/:lang
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LANGFILES:S/$/:lang/}
EXTRACT_ONLY=	# none

MAINTAINER=	gslin@gslin.org
COMMENT=	A fast and lightweight PHP-powered discussion board

BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes
PUNBBDIR?=	${TARGETDIR}/www/punbb
USE_PHP=	yes
USE_ZIP=	yes

OPTIONS=	LANGUAGE_PACK "Install language packs" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LANGUAGE_PACK)
LANGFILES+=	lang_packs-1.2.14/Arabic.zip \
		lang_packs-1.2.14/Bosnian.zip \
		lang_packs-1.2.14/Brazilian_Portuguese.zip \
		lang_packs-1.2.14/Bulgarian.zip \
		lang_packs-1.2.14/Bulgarian_UTF8.zip \
		lang_packs-1.2.14/Catalan.zip \
		lang_packs-1.2.14/Czech.zip \
		lang_packs-1.2.14/Danish.zip \
		lang_packs-1.2.14/Dutch.zip \
		lang_packs-1.2.14/Estonian.zip \
		lang_packs-1.2.14/Farsi.zip \
		lang_packs-1.2.14/Finnish.zip \
		lang_packs-1.2.14/French.zip \
		lang_packs-1.2.14/German.zip \
		lang_packs-1.2.14/Greek.zip \
		lang_packs-1.2.14/Hebrew.zip \
		lang_packs-1.2.14/Hrvatski.zip \
		lang_packs-1.2.14/Hungarian.zip \
		lang_packs-1.2.14/Icelandic.zip \
		lang_packs-1.2.14/Indonesian.zip \
		lang_packs-1.2.14/Italian.zip \
		lang_packs-1.2.14/Japanese.zip \
		lang_packs-1.2.14/Korean.zip \
		lang_packs-1.2.14/Kurdish.zip \
		lang_packs-1.2.14/Latvian.zip \
		lang_packs-1.2.14/Lithuanian.zip \
		lang_packs-1.2.14/Norwegian.zip \
		lang_packs-1.2.14/Polish.zip \
		lang_packs-1.2.14/Portuguese.zip \
		lang_packs-1.2.14/Romanian.zip \
		lang_packs-1.2.14/Russian.zip \
		lang_packs-1.2.14/Serbian.zip \
		lang_packs-1.2.14/Simplified_Chinese.zip \
		lang_packs-1.2.14/Slovak.zip \
		lang_packs-1.2.14/Slovenian.zip \
		lang_packs-1.2.14/Spanish.zip \
		lang_packs-1.2.14/Swedish.zip \
		lang_packs-1.2.14/Traditional_Chinese.zip \
		lang_packs-1.2.14/Turkish.zip \
		lang_packs-1.2.14/Ukrainian.zip \
		lang_packs-1.2.14/Vietnamese.zip
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
