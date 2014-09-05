# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	panda
PORTVERSION=	0.5.4
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	SF \
		SAVANNAH \
		http://www.stillhq.com/panda/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PDF generation library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

USES=		pathfix pkgconfig gmake tar:bzip2
USE_BDB=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-berkeley-db
USE_LDCONFIG=	yes
OPTIONS_DEFINE=	DOCS EXAMPLES

CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include -DHAVE_LIBPNG ${PTHREAD_CFLAGS}
LIBS+=		-lpng
LDFLAGS+=	-L${BDB_LIB_DIR} -L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-extract:
.for file in config.sub config.guess
	@${RM} ${WRKSRC}/config/${file} && ${TOUCH} ${WRKSRC}/config/${file}
.endfor

post-patch:
	${REINPLACE_CMD} -e 's| -lpanda| $$(top_srcdir)/libpanda.la|g' \
		${WRKSRC}/examples/Makefile.in
	${REINPLACE_CMD} -e 's,-ldb,-l${BDB_LIB_NAME},' ${WRKSRC}/configure

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
