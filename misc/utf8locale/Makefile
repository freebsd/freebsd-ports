# New ports collection makefile for:	utf8locale
# Date created:		29 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	utf8locale
PORTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES= 	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
MASTER_SITE_SUBDIR=	perky

MAINTAINER=	perky@FreeBSD.org

LANGS=		en_US ko_KR ja_JP ru_RU zh_CN zh_TW
BASELOCALEDIR=	${DESTDIR}/usr/share/locale
PLIST_SUB=	BASELOCALEDIR=${BASELOCALEDIR} \
		LANGS="${LANGS}"

_HAVE_SWIDTH!=	grep _CTYPE_SW ${DESTDIR}/usr/include/ctype.h || true
.if empty(_HAVE_SWIDTH)
PKGNAMESUFFIX=	-without-swidth
.endif

post-install:
.for lang in ${LANGS}
	-${LN} -sf ${PREFIX}/share/locale/${lang}.UTF-8 \
		${BASELOCALEDIR}/${lang}.UTF-8
.endfor

.include <bsd.port.mk>
