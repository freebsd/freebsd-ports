# New ports collection makefile for:		bitcoin
# Date created:					2011-05-20
# Whom:						Shaun Amott <shaun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitcoin
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net-p2p finance
MASTER_SITES=	https://nodeload.github.com/${PORTNAME}/${PORTNAME}/tarball/	\
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
DISTFILES=	v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
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
CXXFLAGS+=	-Wno-invalid-offsetof

WRKSRC=		${WRKDIR}/bitcoin-bitcoin-72274ed/src

DIST_SUBDIR=	${PORTNAME}

LOCALES=	cs de eo es fr it lt nl pt ro ru sv zh_cn

.include <bsd.port.options.mk>

.if defined(WITH_GUI) && !defined(WITHOUT_X11)
USE_GNOME=	gtk20

#USE_WX=		2.9+

BUILD_DEPENDS+=	${LOCALBASE}/include/wx-2.9/wx/aboutdlg.h:${PORTSDIR}/x11-toolkits/wxgtk29
RUN_DEPENDS+=	${LOCALBASE}/include/wx-2.9/wx/aboutdlg.h:${PORTSDIR}/x11-toolkits/wxgtk29
WX_CONFIG=	${LOCALBASE}/bin/wxgtk2u-2.9-config

BINARY=		bitcoin
PLIST_FILES=	bin/${BINARY}
.else
USE_GNOME=	glib20

BINARY=		bitcoind
ALL_TARGET=	${BINARY}
PLIST_FILES=	bin/${BINARY}
.endif

.if defined(WITH_UPNP)
LIB_DEPENDS+=	miniupnpc:${PORTSDIR}/net/miniupnpc
MAKE_ENV+=	USE_UPNP=yes
.endif

.if !defined(WITHOUT_NLS)
PLIST_FILES+=	${LOCALES:C|^|share/locale/|:C|$|/LC_MESSAGES/bitcoin.mo|}
PLIST_DIRSTRY+=	${LOCALES:C|^|share/locale/|:C|$|/LC_MESSAGES|}
PLIST_DIRSTRY+=	${LOCALES:C|^|share/locale/|}
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${CP} ${WRKSRC}/protocol.h ${WRKSRC}/protocol.h.orig
	@${AWK} 'BEGIN { f = 0 } { if ( $$0 ~ /^#include/ && f == 0 ) { f = 1; print "#include <sys/socket.h>"; print "#include <netinet/in.h>" }; print }' \
		${WRKSRC}/protocol.h.orig > ${WRKSRC}/protocol.h

	@cd ${WRKSRC} && ${CP} -p makefile.unix Makefile
	@${REINPLACE_CMD} \
		-e 's|wx-config|${WX_CONFIG}|g' \
		-e 's|^CXXFLAGS=.*$$|CXXFLAGS += $$(DEFS)|' \
		-e 's|^USE_UPNP.*$$||' \
		-e 's|-l pthread|${PTHREAD_LIBS}|g' \
		-e 's:-O3::' -e 's:-\(march=[A-Za-z0-9]*\)::g' \
		-e 's:-l dl::' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/

.if !defined(WITHOUT_NLS)
.  for lo in ${LOCALES}
	@${MKDIR} ${PREFIX}/share/locale/${lo}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/../locale/${lo}/LC_MESSAGES/bitcoin.mo \
		${PREFIX}/share/locale/${lo}/LC_MESSAGES/
.  endfor
.endif

.include <bsd.port.post.mk>
