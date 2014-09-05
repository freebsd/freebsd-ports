# Created by: Nate Underwood <natey@natey.com>
# $FreeBSD$

PORTNAME=	libpst
PORTVERSION=	0.6.63
PORTREVISION=	2
CATEGORIES=	mail converters
MASTER_SITES=	http://www.five-ten-sg.com/libpst/packages/ \
		http://fossies.org/unix/privat/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for converting Outlook .pst files to mbox and other formats

LICENSE=	GPLv2

LIB_DEPENDS=	libgsf-1.so:${PORTSDIR}/devel/libgsf

OPTIONS_DEFINE=	DOCS PST2DII
OPTIONS_SUB=	yes
PST2DII_DESC=	Allow Summation Document Image Information output

CONFIGURE_ARGS=	--disable-python --enable-libpst-shared
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
USE_LDCONFIG=	yes
USES=		gmake iconv libtool pathfix pkgconfig

PORTDOCS=	*

PST2DII_BUILD_DEPENDS=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
PST2DII_CONFIGURE_OFF=	--enable-dii=no
PST2DII_CONFIGURE_ON=	--enable-dii=yes
PST2DII_LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd
PST2DII_RUN_DEPENDS=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick

post-patch:
	@${GREP} -lr malloc.h ${WRKSRC}/ | ${XARGS} ${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g'
	@${REINPLACE_CMD} -e 's|doc\/@PACKAGE@-@VERSION@|doc\/@PACKAGE@|g' ${WRKSRC}/Makefile.in ${WRKSRC}/html/Makefile.in
	@${REINPLACE_CMD} -e '/html_DATA =/ s|COPYING ||' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpst.so.4.1.10

.include <bsd.port.mk>
