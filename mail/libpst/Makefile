# New ports collection makefile for:   libpst
# Date created:        28 June 2002
# Whom:                Nate Underwood <natey@natey.com>
#
# $FreeBSD$
#

PORTNAME=	libpst
PORTVERSION=	0.6.47
CATEGORIES=	mail converters
MASTER_SITES=	http://www.five-ten-sg.com/libpst/packages/

MAINTAINER=	chifeng@gmail.com
COMMENT=	A tool for converting Outlook .pst files to mbox and other formats

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--disable-python

OPTIONS=	PST2DII "allow Summation Document Image Information output" off

MAN1=	lspst.1 pst2dii.1 pst2ldif.1 readpst.1
MAN5=	outlook.pst.5

.include <bsd.port.options.mk>

.if defined(WITH_PST2DII)
CONFIGURE_ARGS+=	--enable-dii=yes
BUILD_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=	PST2DII=""
.else
CONFIGURE_ARGS+=	--enable-dii=no
PLIST_SUB+=	PST2DII="@comment "
.endif

post-patch:
	${FIND} -X ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -i "" \
		-e 's/malloc.h/stdlib.h/g'
	${REINPLACE_CMD} -e 's;doc\/@PACKAGE@-@VERSION@;doc\/@PACKAGE@;g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/html/Makefile.in
.ifdef(NOPORTDOCS)
	${REINPLACE_CMD} -e '/SUBDIRS =/s/=.*/= src man/' -e '/html_DATA =/d' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
