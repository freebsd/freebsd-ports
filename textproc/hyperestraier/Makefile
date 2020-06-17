# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports-stable/textproc/hyperestraier/Makefile,v 1.3 2006/10/17 11:45:45 ahze Exp $

PORTNAME=	hyperestraier
PORTVERSION=	1.4.13
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-text search system

BUILD_DEPENDS=	qdbm>=1.8.77:databases/qdbm
# check configure for min version of qdbm.
LIB_DEPENDS=	libqdbm.so.14:databases/qdbm

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-bzip2 --disable-zlib
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	LZO MECAB
LZO_DESC=	Enable lzo support
MECAB_DESC=	Enable mecab support

LZO_CONFIGURE_ENABLE=	lzo
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2

MECAB_CONFIGURE_ENABLE=	mecab
MECAB_LIB_DEPENDS=	libmecab.so:japanese/mecab
MECAB_RUN_DEPENDS=	ja-mecab-ipadic>0:japanese/mecab-ipadic

post-patch:
	@${REINPLACE_CMD} -e 's/@MYCFLAGS@/@CFLAGS@ -Wall -fPIC -fsigned-char/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure
	@${RM} ${WRKSRC}/doc/intro-en.html~ ${WRKSRC}/doc/intro-ja.html~

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libestraier.so

.include <bsd.port.mk>
