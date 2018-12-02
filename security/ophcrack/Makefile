# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ophcrack
PORTVERSION=	3.7.0
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

OPTIONS_DEFINE=	X11 GRAPH DOCS
OPTIONS_DEFAULT=	X11 GRAPH
GRAPH_IMPLIES=	X11

X11_DESC=	Build Qt 4 GUI frontend
GRAPH_DESC=	Enable graph rendering via Qwt

X11_USES=	qt:4
X11_USE=	QT=moc_build,qmake_build,rcc_build,uic_build,corelib,gui
X11_CONFIGURE_OFF=	--disable-gui

GRAPH_LIB_DEPENDS=	libqwt.so:x11-toolkits/qwt5
GRAPH_CONFIGURE_OFF=	--disable-graph

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

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
