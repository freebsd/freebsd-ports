# New ports collection makefile for:	estraier
# Date created:		2004-08-28
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	estraier
PORTVERSION=	1.2.25
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A full-text search system for personal use

LIB_DEPENDS=	qdbm.3:${PORTSDIR}/databases/qdbm

USE_ICONV=	yes

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--with-sysqdbm \
		--enable-dlfilter \
		--enable-devel

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/include ${PTHREAD_LIBS}"

OPTIONS=	CHASEN "Japanese Morphological Analysis Support" On \
		MECAB "Part-of-Speech and Morphological Analyzer" On \
		KAKASI "Language processing filter/converter" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CHASEN)
LIB_DEPENDS+=	chasen.0:${PORTSDIR}/japanese/chasen-base

CONFIGURE_ARGS+=	--enable-chasen
.endif

.if ${ARCH} == i386 && !defined(WITHOUT_MECAB)
LIB_DEPENDS+=	mecab.0:${PORTSDIR}/japanese/mecab

CONFIGURE_ARGS+=	--enable-mecab
.endif

.if !defined(WITHOUT_KAKASI)
LIB_DEPENDS+=	kakasi.3:${PORTSDIR}/japanese/kakasi

CONFIGURE_ARGS+=	--enable-kakasi
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' ${WRKSRC}/configure ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
