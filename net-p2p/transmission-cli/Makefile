PORTNAME=	transmission
DISTVERSION=	3.00
PORTREVISION?=	5
CATEGORIES+=	net-p2p
SLAVEPORT?=	cli
PKGNAMESUFFIX?=	-cli

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Meta-port for Transmission BitTorrent client

LICENSE+=	MIT

.if ${SLAVEPORT:Ncli}
LICENSE+=	GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING
.endif

.if ${SLAVEPORT:Nweb}
LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libdht.so:devel/jech-dht \
		libb64.so:converters/libb64 \
		libevent.so:devel/libevent \
		libnatpmp.so:net/libnatpmp \
		libutp.so:net/libutp \
		libminiupnpc.so:net/miniupnpc

USES+=		cmake cpe iconv libtool localbase pkgconfig ssl

# Workaround: PR 248326
# https://github.com/transmission/transmission/issues/1359
CFLAGS+=	-DNDEBUG

.  if ${SLAVEPORT:Mcli}
NLS_USES=	gettext-runtime:run
.  endif

CPE_VENDOR=	transmissionbt
.endif

USE_GITHUB=	yes

.if ${SLAVEPORT:Nutils}
CMAKE_OFF+=	ENABLE_UTILS
.endif

.if ${SLAVEPORT:Nweb}
SLAVES=		cli daemon gtk qt utils
CMAKE_ON+=	ENABLE_${SLAVEPORT:tu}
CMAKE_OFF+=	${SLAVES:N${SLAVEPORT}:tu:S/^/ENABLE_/}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${SLAVEPORT}
CMAKE_ARGS+=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}

OPTIONS_DEFINE+=	DOCS LITE NLS
OPTIONS_SUB=		yes

NLS_CMAKE_BOOL=		ENABLE_NLS
LITE_CMAKE_BOOL=	ENABLE_LIGHTWEIGHT
.endif

post-extract:
	@${FIND} ${WRKSRC}/web -name .git* -delete

.if ${SLAVEPORT:Mweb}
	@${FIND} ${WRKSRC}/web \( -name '*.am' -o -name '*.in' \
		-o -name '*.scss' \) -delete

do-install:
	( cd ${WRKSRC} && ${COPYTREE_SHARE} web ${STAGEDIR}${DATADIR} )
.endif

.if ${SLAVEPORT:Mdaemon}
post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/home
.endif

.if ${SLAVEPORT:Mqt}
post-install:
	${REINPLACE_CMD} -e "s/Icon=.*/&-qt/" \
		${STAGEDIR}${DESKTOPDIR}/transmission-qt.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/qt/icons/transmission.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/transmission-qt.png
.endif

.include <bsd.port.mk>
