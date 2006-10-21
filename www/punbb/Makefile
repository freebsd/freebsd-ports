# New ports collection makefile for:	punbb
# Date created:		2006-08-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	punbb
PORTVERSION=	1.2.12
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.punbb.org/download/ \
		http://punbb.pxtek.com/ \
		http://punbb.nhost.co.uk/ \
		http://mirror.ordo.dk/punbb.org/ \
		http://punbb.mirrors.typhon.net/ \
		http://punbb.4any.org/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${LANGFILES}
EXTRACT_ONLY=	# none

MAINTAINER=	gslin@gslin.org
COMMENT=	A fast and lightweight PHP-powered discussion board

BROKEN=		Checksum mismatch

NO_BUILD=	yes
PUNBBDIR?=	${TARGETDIR}/www/punbb
USE_PHP=	yes
USE_ZIP=	yes
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

OPTIONS=	LANGUAGE_PACK "Install language packs" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LANGUAGE_PACK)
LANGFILES+=	lang_packs-1.2/Arabic.zip \
		lang_packs-1.2/Bosnian.zip \
		lang_packs-1.2/Brazilian_Portuguese.zip \
		lang_packs-1.2/Bulgarian.zip \
		lang_packs-1.2/Bulgarian_UTF8.zip \
		lang_packs-1.2/Catalan.zip \
		lang_packs-1.2/Czech.zip \
		lang_packs-1.2/Danish.zip \
		lang_packs-1.2/Dutch.zip \
		lang_packs-1.2/Estonian.zip \
		lang_packs-1.2/Farsi.zip \
		lang_packs-1.2/Finnish.zip \
		lang_packs-1.2/French.zip \
		lang_packs-1.2/German.zip \
		lang_packs-1.2/Greek.zip \
		lang_packs-1.2/Hebrew.zip \
		lang_packs-1.2/Hrvatski.zip \
		lang_packs-1.2/Hungarian.zip \
		lang_packs-1.2/Icelandic.zip \
		lang_packs-1.2/Indonesian.zip \
		lang_packs-1.2/Italian.zip \
		lang_packs-1.2/Japanese.zip \
		lang_packs-1.2/Korean.zip \
		lang_packs-1.2/Kurdish.zip \
		lang_packs-1.2/Latvian.zip \
		lang_packs-1.2/Lithuanian.zip \
		lang_packs-1.2/Norwegian.zip \
		lang_packs-1.2/Polish.zip \
		lang_packs-1.2/Portuguese.zip \
		lang_packs-1.2/Romanian.zip \
		lang_packs-1.2/Russian.zip \
		lang_packs-1.2/Serbian.zip \
		lang_packs-1.2/Simplified_Chinese.zip \
		lang_packs-1.2/Slovak.zip \
		lang_packs-1.2/Slovenian.zip \
		lang_packs-1.2/Spanish.zip \
		lang_packs-1.2/Swedish.zip \
		lang_packs-1.2/Traditional_Chinese.zip \
		lang_packs-1.2/Turkish.zip \
		lang_packs-1.2/Ukrainian.zip \
		lang_packs-1.2/Vietnamese.zip
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
