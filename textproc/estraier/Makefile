# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	estraier
PORTVERSION=	1.2.30
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://fallabs.com/estraier/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-text search system for personal use

LIB_DEPENDS=	qdbm.14:${PORTSDIR}/databases/qdbm

OPTIONS_DEFINE=	CHASEN MECAB KAKASI
OPTIONS_DEFAULT=	KAKASI
CHASEN_DESC=	Japanese Morphological Analysis Support
MECAB_DESC=	Part-of-Speech and Morphological Analyzer
KAKASI_DESC=	Language processing filter/converter

USES=		iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sysqdbm \
		--enable-dlfilter \
		--enable-devel
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/include ${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCHASEN}
LIB_DEPENDS+=	chasen.2:${PORTSDIR}/japanese/chasen-base
CONFIGURE_ARGS+=	--enable-chasen
.endif

.if ${PORT_OPTIONS:MMECAB} && ${ARCH} == "i386"
LIB_DEPENDS+=	mecab.1:${PORTSDIR}/japanese/mecab
CONFIGURE_ARGS+=	--enable-mecab
.endif

.if ${PORT_OPTIONS:MKAKASI}
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
