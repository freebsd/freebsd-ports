# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	sdcv
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based utility for work with dictionaries in StarDict's format

OPTIONS_DEFINE=	NLS

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20
USES=		pkgconfig iconv
SUB_FILES=	pkg-message

NLS_USES=	gettext
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/doc/sdcv.1
	@${REINPLACE_CMD} -e '1425 s, install-data,,' \
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's, getopt.h,,g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '146 s|()|(int, char * const [], const char *)|g' \
		${WRKSRC}/src/getopt.h
	@${REINPLACE_CMD} -e '516 s|sizeof|(guint32)sizeof|g' \
		${WRKSRC}/src/lib/lib.cpp
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/sdcv.cpp
	@${REINPLACE_CMD} -e 's,@mandir@/uk,@mandir@,' \
		${WRKSRC}/doc/uk/Makefile.in

.include <bsd.port.mk>
