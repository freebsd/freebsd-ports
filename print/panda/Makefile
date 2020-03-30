# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	panda
PORTVERSION=	0.5.4
PORTREVISION=	10
CATEGORIES=	print
MASTER_SITES=	SF \
		SAVANNAH \
		http://www.stillhq.com/panda/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PDF generation library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-berkeley-db
CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LIBS+=		-lz -L${BDB_LIB_DIR} -L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		autoreconf bdb dos2unix gmake jpeg libtool pathfix pkgconfig tar:bzip2
DOS2UNIX_GLOB=	*.c
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/panda_*.3 ${STAGEDIR}${MANPREFIX}/man/man3
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS CONTRIBUTORS ChangeLog DEV-HINTS README TODO UNDERWAY
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in IMAGES examples/*.c examples/c++/*.cpp examples/images/*.*
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
