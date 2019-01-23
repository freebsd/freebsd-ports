# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ophcrack
PORTVERSION=	3.8.0
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Windows password cracker based on rainbow tables

LICENSE=	APACHE20 GPLv2
LICENSE_COMB=	multi

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		gmake localbase ssl tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ophcrack
PORTDOCS=	AUTHORS ChangeLog README.md

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=	X11

X11_DESC=	Build with Qt 5 GUI frontend

X11_USES=	pkgconfig qt:5
X11_USE=	QT=buildtools_build,qmake_build,charts,core,gui,widgets
X11_CONFIGURE_OFF=	--disable-gui

post-patch:
	@${REINPLACE_CMD} -E '/#include <byteswap\.h>/d ; \
		/#include/s,"bswap\.h",<machine/endian.h>, ; \
		s,bswap_([[:digit:]]+),bswap\1, ' \
			${WRKSRC}/src/samdump2/bkhive.c \
			${WRKSRC}/src/samdump2/hive.c \
			${WRKSRC}/src/samdump2/samdump2.c \
			${WRKSRC}/src/core/misc.h

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
