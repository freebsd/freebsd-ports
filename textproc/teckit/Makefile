PORTNAME=	teckit
DISTVERSION=	2.5.11
CATEGORIES=	textproc converters
MASTER_SITES=	https://github.com/silnrsi/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Toolkit for converting data between 8-bit legacy encodings and Unicode

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/license/LICENSING.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

DOCS=		AUTHORS README NEWS docs/*.pdf license/LICENSING.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/sfconv_CXXFLAGS = -std=c++11/d' \
		${WRKSRC}/bin/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
