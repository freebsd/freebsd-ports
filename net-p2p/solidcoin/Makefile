# Created by: Dmitriy Limonov
# $FreeBSD$

PORTNAME=	solidcoin
PORTVERSION=	2.041
PORTREVISION=	6
CATEGORIES=	net-p2p finance
MASTER_SITES=	http://downloads.solidcoin.info/ \
		http://dl.dropbox.com/u/47582909/
DISTNAME=	${PORTNAME}-source-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative Bitcoin peer-to-peer currency client

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/parallel/algorithm.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

BROKEN=		Does not build with any of the supported wx

OPTIONS_DEFINE=	WXGTK
OPTIONS_DEFAULT=	WXGTK

WRKSRC=		${WRKDIR}/src

USES=		gmake dos2unix zip
USE_GNOME=	glib20
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	47
USE_GCC=	any
ALL_TARGET=	${BINARY}

CXXFLAGS+=	-Wno-invalid-offsetof
CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${BDB_LIB_DIR} -L${LOCALBASE}/lib

PLIST_FILES=	bin/${BINARY}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWXGTK}
USE_WX=		3.0
WX_UNICODE=	yes
PLIST_FILES+=	share/pixmaps/solidcoin48.xpm
DESKTOP_ENTRIES="SolidCoin" "" "${PREFIX}/share/pixmaps/solidcoin48.xpm" \
		"${PORTNAME}" "" true
BINARY=		solidcoin
.else
BINARY=		solidcoind
.endif

post-patch:
.for i in crypto gui nogui
	@${MKDIR} ${WRKSRC}/../obj/${i}
.endfor
	@${ECHO_CMD} '18i\' > ${WRKDIR}/sed.in
	@${ECHO_CMD} '#ifndef __STDC_LIMIT_MACROS' >> ${WRKDIR}/sed.in
	@${ECHO_CMD} '19i\' >> ${WRKDIR}/sed.in
	@${ECHO_CMD} '#endif' >> ${WRKDIR}/sed.in
	@${REINPLACE_CMD} \
		-f ${WRKDIR}/sed.in \
		${WRKSRC}/headers.h

do-configure:
	@cd ${WRKSRC} && ${SED} -e \
		's|^CXX=|CXX?=| ; \
		 s|shell .* |shell $$(WX_CONFIG) | ; \
		 s|-Wl,-Bstatic|| ; ; \
		 s|-Wl,-Bdynamic|| ; \
		 /-l dl/d ; \
		 s|-l pthread|$$(LDFLAGS)|; \
		 s|^CXXFLAGS=-O2|CXXFLAGS+=$$(CPPFLAGS)|' \
		< ../build/makefile.unix > Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${BINARY} ${PREFIX}/bin)
.if ${PORT_OPTIONS:MWXGTK}
	(cd ${WRKSRC}/../share/xpm && ${INSTALL_DATA} solidcoin48.xpm \
		${PREFIX}/share/pixmaps)
.endif

.include <bsd.port.mk>
