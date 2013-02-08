# Created by: Dmitriy Limonov
# $FreeBSD$

PORTNAME=	solidcoin
PORTVERSION=	2.041
PORTREVISION=	3
CATEGORIES=	net-p2p finance
MASTER_SITES=	http://solidcoin.info/downloads/ \
		http://dl.dropbox.com/u/47582909/
DISTNAME=	${PORTNAME}-source-2041

MAINTAINER=	earl1k@mail.ru
COMMENT=	Alternative Bitcoin peer-to-peer currency client

BROKEN=		Does not build

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/parallel/algorithm.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	boost_date_time:${PORTSDIR}/devel/boost-libs

OPTIONS=	GUI "Build with wxWidgets GUI" on

USE_ZIP=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	47
MAKE_JOBS_SAFE=	yes

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

WRKSRC=		${WRKDIR}/src

.include <bsd.port.options.mk>

.if defined(WITH_GUI) && !defined(WITHOUT_X11)
USE_WX=		2.9
DESKTOP_ENTRIES="Solidcoin" "${COMMENT}" "" "${PORTNAME}" "" "true"

WX_CONFIG=	${LOCALBASE}/bin/wxgtk2u-2.9-config
BINARY=		solidcoin
.else
USE_GNOME=	glib20

BINARY=		solidcoind
ALL_TARGET=	${BINARY}
.endif

PLIST_FILES=	bin/${BINARY}

post-extract:
	@${CP} ${WRKSRC}/../build/makefile.unix ${WRKSRC}/Makefile

post-patch:
.for i in crypto gui nogui
	@${MKDIR}  ${WRKSRC}/../obj/$i
.endfor
	@echo '18i\' > ${WRKSRC}/sed.in
	@echo '#ifndef __STDC_LIMIT_MACROS' >> ${WRKSRC}/sed.in
	@echo '19i\' >> ${WRKSRC}/sed.in
	@echo '#endif' >> ${WRKSRC}/sed.in
	@${REINPLACE_CMD} \
		-f ${WRKSRC}/sed.in \
		${WRKSRC}/headers.h
	@${REINPLACE_CMD} \
		-e 's|^CXXFLAGS=.*$$|CXXFLAGS += $$(DEFS)|' \
		-e '/-l dl/d' \
		-e 's|../../wxWidgets-2.9.2/wx-config|${WX_CONFIG}|' \
		${WRKSRC}/Makefile
do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/

.include <bsd.port.mk>
