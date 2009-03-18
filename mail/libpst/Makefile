# New ports collection makefile for:   libpst
# Date created:        28 June 2002
# Whom:                Nate Underwood <natey@natey.com>
#
# $FreeBSD$
#

PORTNAME=	libpst
PORTVERSION=	0.6.32
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

.if exists(${LOCALBASE}/bin/convert) || defined(WITH_PST2DII)
BUILD_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
PLIST_SUB+=	PST2DII=""
.else
PLIST_SUB+=	PST2DII="@comment "
.endif

MAN1=	lspst.1 pst2dii.1 pst2ldif.1 readpst.1 readpstlog.1
MAN5=	outlook.pst.5

post-patch:
	${FIND} -X ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e 's/malloc.h/stdlib.h/g'
	${REINPLACE_CMD} -e 's;doc\/@PACKAGE@-@VERSION@;doc\/@PACKAGE@;g' ${WRKSRC}/Makefile.in \
	${WRKSRC}/html/Makefile.in

.ifdef(NOPORTDOCS)
INSTALL_TARGET=	install-exec

post-install:
	@(cd ${WRKSRC}/man && ${GMAKE} ${MAKE_ARGS} install)
.endif

.include <bsd.port.mk>
