PORTNAME=	i2pd
DISTVERSION=	2.58.0
CATEGORIES=	security net-p2p

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	C++ implementation of I2P client
WWW=		https://i2pd.website/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>=1.72.0_5:devel/boost-libs
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:insource compiler:c++17-lang ssl
USE_GITHUB=	yes
GH_ACCOUNT=	PurpleI2P
USE_RC_SUBR=	${PORTNAME}

CMAKE_SOURCE_PATH=	${WRKSRC}/build

SUB_FILES=	i2pd.newsyslog.conf pkg-message
SUB_LIST=	CERTSDIR=${_CERTSDIR} \
		GROUP="${GROUPS}" \
		USER="${USERS}" \
		WRITEDATADIR=${_WRITEDATADIR}

USERS=		_i2pd
GROUPS=		_i2pd

PLIST_SUB=	GROUP="${GROUPS}" \
		USER="${USERS}"

PORTDOCS=	README.md

OPTIONS_DEFINE=		AESNI DOCS HARDENING UPNP
OPTIONS_DEFAULT=	AESNI

AESNI_DESC=	Use AES-NI instructions set
HARDENING_DESC=	Use hardening compiler flags
UPNP_DESC=	Include support for UPnP client

AESNI_CMAKE_BOOL=	WITH_AESNI

HARDENING_CMAKE_BOOL=	WITH_HARDENING

UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CMAKE_BOOL=	WITH_UPNP

_CERTSDIR=	${DATADIR}/certificates
_WRITEDATADIR=	/var/db/${PORTNAME}

post-patch: # fix config file
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g' ${WRKSRC}/contrib/i2pd.conf
	@${REINPLACE_CMD} -e 's|%%CERTSDIR%%|${_CERTSDIR}|g' ${WRKSRC}/contrib/i2pd.conf
	@${REINPLACE_CMD} -e 's|/var/lib/${PORTNAME}|${_WRITEDATADIR}|g' ${WRKSRC}/contrib/i2pd.conf

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKDIR}/i2pd.newsyslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/i2pd.conf.sample
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/i2pd.conf ${STAGEDIR}${ETCDIR}/i2pd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/contrib/tunnels.conf ${STAGEDIR}${ETCDIR}/tunnels.conf.sample
	@(cd ${WRKSRC}/contrib/certificates && ${COPYTREE_SHARE} . ${STAGEDIR}${_CERTSDIR})
	@${MKDIR} ${STAGEDIR}/var/run/i2pd
	@${MKDIR} ${STAGEDIR}/var/log/i2pd
	@${MKDIR} ${STAGEDIR}/var/db/i2pd
	@${MKDIR} ${STAGEDIR}${ETCDIR}/tunnels.d

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
