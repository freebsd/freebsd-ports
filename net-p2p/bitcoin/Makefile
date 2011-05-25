# New ports collection makefile for:		bitcoin
# Date created:					2011-05-20
# Whom:						Shaun Amott <shaun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitcoin
PORTVERSION=	0.3.21
PORTREVISION=	1
CATEGORIES=	net-p2p finance
MASTER_SITES=	https://download.github.com/		\
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
DISTFILES=	bitcoin-bitcoin-v${PORTVERSION}-0-g64ad448.tar.gz

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Virtual Peer-to-Peer Currency Client

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/parallel/algorithm.hpp:${PORTSDIR}/devel/boost-libs # 1.40+
LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs

OPTIONS=	GUI  "Build with wxWidgets GUI" on	\
		UPNP "Build with UPNP support"  off

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	47	# 4.8 doesn't work

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}

WRKSRC=		${WRKDIR}/bitcoin-bitcoin-1f578d2

.include <bsd.port.options.mk>

.if defined(WITH_GUI) && !defined(WITHOUT_X11)
USE_GNOME=	gtk20

#USE_WX=		2.9+

BUILD_DEPENDS+=	${LOCALBASE}/include/wx-2.9/wx/aboutdlg.h:${PORTSDIR}/x11-toolkits/wxgtk29
WX_CONFIG=	${LOCALBASE}/bin/wxgtk2u-2.9-config

BINARY=		bitcoin
PLIST_FILES=	bin/${BINARY}
.else
BINARY=		bitcoind
ALL_TARGET=	${BINARY}
PLIST_FILES=	bin/${BINARY}
.endif

.if defined(WITH_UPNP)
LIB_DEPENDS+=	miniupnpc:${PORTSDIR}/net/miniupnpc
MAKE_ENV+=	-DUSE_UPNP
.endif

.include <bsd.port.pre.mk>

pre-fetch:
.if ${MASTER_SITES:M*github.com*} != "" && !exists(${DISTDIR}/${DISTFILES})
	@${ECHO_MSG} "===>  Pinging github to vivify tarball..."
	@(cd ${DISTDIR} && \
		${FETCH_BINARY} -Ap https://nodeload.github.com/bitcoin/bitcoin/tarball/v${PORTVERSION} 2>/dev/null \
		|| ${TRUE} \
	)
.endif

post-patch:
	cd ${WRKSRC} && ${CP} -p makefile.unix Makefile
	${REINPLACE_CMD} \
		-e 's|wx-config|${WX_CONFIG}|g' \
		-e 's|^CXXFLAGS=.*$$|CXXFLAGS += $$(DEFS)|' \
		-e 's|^USE_UPNP.*$$||' \
		-e 's:-O3::' -e 's:-\(march=[A-Za-z0-9]*\)::g' \
		-e 's:-l z \\:-l z:' \
		-e 's:-l dl::' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/

.include <bsd.port.post.mk>
