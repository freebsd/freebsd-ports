# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports-stable/textproc/hyperestraier/Makefile,v 1.3 2006/10/17 11:45:45 ahze Exp $

PORTNAME=	hyperestraier
PORTVERSION=	1.4.13
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full-text search system

BUILD_DEPENDS=	qdbm>=1.8.77:${PORTSDIR}/databases/qdbm
# check configure for min version of qdbm.
LIB_DEPENDS=	libqdbm.so.14:${PORTSDIR}/databases/qdbm

USES=		iconv
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-bzip2 --disable-zlib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	LZO MECAB
LZO_DESC=	Enable lzo support
MECAB_DESC=	Enable mecab support

LZO_CONFIGURE_ENABLE=	lzo
LZO_LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2

MECAB_CONFIGURE_ENABLE=	mecab
MECAB_LIB_DEPENDS=	libmecab.so:${PORTSDIR}/japanese/mecab
MECAB_RUN_DEPENDS=	${LOCALBASE}/lib/mecab/dic/ipadic/matrix.bin:${PORTSDIR}/japanese/mecab-ipadic

post-patch:
	@${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	${RM} -f ${WRKSRC}/doc/intro-en.html~ ${WRKSRC}/doc/intro-ja.html~

.include <bsd.port.mk>
