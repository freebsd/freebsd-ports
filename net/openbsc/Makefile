# $FreeBSD$

PORTNAME=	openbsc
PORTVERSION=	0.15.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://git.osmocom.org/${PORTNAME}/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	GSM network in a box software

LICENSE=	GPLv3

LIB_DEPENDS=	libdbi.so:databases/libdbi \
		libosmocore.so:devel/libosmocore \
		libosmoabis.so:devel/libosmo-abis \
		libosmonetif.so:devel/libosmo-netif \
		libdbi.so:databases/libdbi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

USES=		autoreconf compiler:c11 gmake pathfix pkgconfig ssl
GNU_CONFIGURE=	yes
AUTOMAKE_ARGS=	--gnu --add-missing --copy
CONFIGURE_ARGS+=	CFLAGS="-I${LOCALBASE}/include"

OPTIONS_DEFINE=	BSC NAT SQLITE
OPTIONS_DEFAULT= BSC NAT

BSC_DESC=	Enable OSMO BSC
NAT_DESC=	Enable NAT support
SQLITE_DESC=	Enable SQLite support

OPTIONS_SUB=	yes

BSC_CONFIGURE_ENABLE=	osmo-bsc

NAT_CONFIGURE_ENABLE=	nat
NAT_BUILD_DEPENDS=	${LOCALBASE}/lib/libsccp.a:devel/libosmo-sccp
NAT_RUN_DEPENDS=	${LOCALBASE}/lib/libsccp.a:devel/libosmo-sccp

SQLITE_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

post-patch:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
