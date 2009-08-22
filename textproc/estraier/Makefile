# New ports collection makefile for:	estraier
# Date created:		2004-08-28
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	estraier
PORTVERSION=	1.2.29
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF \
		http://estraier.sourceforge.net/


MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A full-text search system for personal use

LIB_DEPENDS=	qdbm.14:${PORTSDIR}/databases/qdbm

USE_ICONV=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-sysqdbm \
		--enable-dlfilter \
		--enable-devel

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/include ${PTHREAD_LIBS}"

OPTIONS=	CHASEN "Japanese Morphological Analysis Support" Off \
		MECAB "Part-of-Speech and Morphological Analyzer" Off \
		KAKASI "Language processing filter/converter" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CHASEN)
LIB_DEPENDS+=	chasen.2:${PORTSDIR}/japanese/chasen-base

CONFIGURE_ARGS+=	--enable-chasen
.endif

.if ${ARCH} == i386 && defined(WITH_MECAB)
LIB_DEPENDS+=	mecab.1:${PORTSDIR}/japanese/mecab

CONFIGURE_ARGS+=	--enable-mecab
.endif

.if !defined(WITHOUT_KAKASI)
LIB_DEPENDS+=	kakasi.3:${PORTSDIR}/japanese/kakasi

CONFIGURE_ARGS+=	--enable-kakasi
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' ${WRKSRC}/configure ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
