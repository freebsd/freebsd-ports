# New ports collection makefile for:	estraier
# Date created:		2004-08-28
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	estraier
PORTVERSION=	1.2.30
CATEGORIES=	textproc
MASTER_SITES=	http://fallabs.com/estraier/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-text search system for personal use

LIB_DEPENDS=	qdbm.14:${PORTSDIR}/databases/qdbm

OPTIONS=	CHASEN "Japanese Morphological Analysis Support" Off \
		MECAB "Part-of-Speech and Morphological Analyzer" Off \
		KAKASI "Language processing filter/converter" On

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sysqdbm \
		--enable-dlfilter \
		--enable-devel
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/include ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if defined(WITH_CHASEN)
LIB_DEPENDS+=	chasen.2:${PORTSDIR}/japanese/chasen-base
CONFIGURE_ARGS+=	--enable-chasen
.endif

.if defined(WITH_MECAB) && ${ARCH} == "i386"
LIB_DEPENDS+=	mecab.1:${PORTSDIR}/japanese/mecab
CONFIGURE_ARGS+=	--enable-mecab
.endif

.if !defined(WITHOUT_KAKASI)
LIB_DEPENDS+=	kakasi.3:${PORTSDIR}/japanese/kakasi
CONFIGURE_ARGS+=	--enable-kakasi
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lc ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-O2|@CFLAGS@|g ; \
		 s|HOME|LOCALBASE|g ; \
		 s|:/usr/local/lib||g ; \
		 s|-I/usr/local/include|${PTHREAD_CFLAGS}|g ; \
		 s|-L/usr/local/lib|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile.in

post-install:
.for file in estindex estmbtomh estserver estsiutil estxview
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.post.mk>
