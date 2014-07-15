# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	twister-core
PORTVERSION=	0.140629
CATEGORIES=	net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Experimental peer-to-peer microblogging software

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs	\
		libleveldb.so:${PORTSDIR}/databases/leveldb	\
		libicui18n.so:${PORTSDIR}/devel/icu

OPTIONS_DEFINE=		UPNP DOCS
OPTIONS_DEFAULT=	UPNP
UPNP_DESC=		UPnP port mapping
UPNP_LIB_DEPENDS=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc

USE_GITHUB=	yes
GH_ACCOUNT=	miguelfreitas
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	7474196

USE_BDB=	yes
WANT_BDB_VER=	48
USE_OPENSSL=	yes
USES=		gmake iconv

USE_AUTOTOOLS=	libtoolize:env aclocal:env autoconf:env autoheader:env automake:env
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=${WRKSRC}/libtorrent
CONFIGURE_ARGS=	--with-libiconv			\
		--with-boost=${LOCALBASE}	\
		--with-boost-system=boost_system
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKEFILE=	makefile.freebsd
BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ENV=	BOOST_INCLUDE_PATH=${LOCALBASE}/include	\
		BOOST_LIB_PATH=${LOCALBASE}/lib		\
		BDB_INCLUDE_PATH=${BDB_INCLUDE_DIR}	\
		BDB_LIB_PATH=${BDB_LIB_DIR}		\
		ICONV_LIB="${ICONV_LIB}"

PLIST_FILES=	bin/twisterd
PORTDOCS=	README.md

.include <bsd.port.options.mk>

.if (${OPSYS} == FreeBSD && ${OSVERSION} < 1000000)
WITH_OPENSSL_PORT=	yes
.endif

pre-configure:
	(cd ${CONFIGURE_WRKSRC} && ./autotool.sh)
.if ${PORT_OPTIONS:MUPNP}
	${REINPLACE_CMD} -e 's|USE_UPNP:=1|USE_UPNP:=|' ${BUILD_WRKSRC}/${MAKEFILE}
.endif

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/twisterd ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
