# New ports collection makefile for:	utf8locale
# Date created:		29 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	utf8locale
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES= 	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky

MAINTAINER=	perky@FreeBSD.org

LANGS=		en_US ko_KR ja_JP
BASELOCALEDIR=	${DESTDIR}/usr/share/locale
PLIST_SUB=	BASELOCALEDIR=${BASELOCALEDIR} \
		LANGS="${LANGS}"

post-install:
.for lang in ${LANGS}
	-${LN} -sf ${PREFIX}/share/locale/${lang}.UTF-8 \
		${BASELOCALEDIR}/${lang}.UTF-8
.endfor

.include <bsd.port.mk>
