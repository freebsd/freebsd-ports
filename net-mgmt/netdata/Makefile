# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME=	netdata
PORTVERSION=	1.19.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Scalable distributed realtime performance and health monitoring

LICENSE=	GPLv3

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl

USES=		autoreconf cpe pathfix pkgconfig:both python shebangfix ssl

USE_GITHUB=	yes

SHEBANG_GLOB=	*

NETDATA_CACHE=	/var/cache/${PORTNAME}
NETDATA_LOG=	/var/log/${PORTNAME}
NETDATA_PERST=	/var/db/${PORTNAME}

GNU_CONFIGURE=	yes
CPPFLAGS+=	-D_WANT_VMMETER -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

SUB_LIST=	NETDATA_CACHE=${NETDATA_CACHE} \
		NETDATA_LOG=${NETDATA_LOG} \
		NETDATA_PERST=${NETDATA_PERST}

PLIST_SUB=	NETDATA_CACHE=${NETDATA_CACHE} \
		NETDATA_LOG=${NETDATA_LOG} \
		NETDATA_PERST=${NETDATA_PERST}

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	${PORTNAME}.conf.sample

USERS=		netdata
GROUPS=		netdata

OPTIONS_DEFINE=		CUPS DBENGINE FREEIPMI JSON LTO
OPTIONS_SUB=		YES
OPTIONS_DEFAULT=	DBENGINE JSON
OPTIONS_DEFAULT_FreeBSD_12=	LTO
OPTIONS_DEFAULT_FreeBSD_13=	LTO
OPTIONS_DEFAULT+=	${OPTIONS_DEFAULT_${OPSYS}_${OSREL:R}}

CUPS_DESC=		Enable support for cups
CUPS_CONFIGURE_ENABLE=	plugin-cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DBENGINE_DESC=			Enable support for database engine
DBENGINE_CONFIGURE_ENABLE=	dbengine
DBENGINE_LIB_DEPENDS=		libJudy.so:devel/judy \
				liblz4.so:archivers/liblz4 \
				libuv.so:devel/libuv

FREEIPMI_DESC=			Enable support for freeipmi
FREEIPMI_CONFIGURE_ENABLE=	plugin-freeipmi
FREEIPMI_LIB_DEPENDS=		libfreeipmi.so:sysutils/freeipmi

JSON_DESC=		Enable support for json
JSON_CONFIGURE_ENABLE=	jsonc
JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c

LTO_DESC=		Use Link-Time Optimization
LTO_CONFIGURE_ENABLE=	lto
LTO_USES=		compiler:c11

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MLTO} && ${OPSYS}_${OSREL:R} == FreeBSD_11
BROKEN=		Link-Time Optimization breaks compilation on FreeBSD 11
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%NETDATA_CACHE%%|${NETDATA_CACHE}|g' \
	    ${PATCH_WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%NETDATA_LOG%%|${NETDATA_LOG}|g' \
	    ${PATCH_WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%NETDATA_PERST%%|${NETDATA_PERST}|g' \
	    ${PATCH_WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g' \
	    ${PATCH_WRKSRC}/configure.ac

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/netdata.conf.sample ${STAGEDIR}${ETCDIR}/netdata.conf.sample
	${MKDIR} ${STAGEDIR}${NETDATA_CACHE}
	${MKDIR} ${STAGEDIR}${NETDATA_LOG}
	${MKDIR} ${STAGEDIR}${NETDATA_PERST}
	(for file in ${STAGEDIR}${LOCALBASE}/lib/${PORTNAME}/conf.d/*.conf \
			${STAGEDIR}${LOCALBASE}/lib/${PORTNAME}/conf.d/*/*.conf; do \
		${MV} $$file $$file".sample"; \
	done)

.include <bsd.port.mk>
