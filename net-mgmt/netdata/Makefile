# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME=	netdata
PORTVERSION=	1.21.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scalable distributed realtime performance and health monitoring

LICENSE=	GPLv3

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libuuid.so:misc/e2fsprogs-libuuid \
		libuv.so:devel/libuv

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}

USES=		autoreconf cpe pathfix pkgconfig:both python shebangfix ssl

USE_GITHUB=	yes

SHEBANG_GLOB=	*

NETDATA_CACHE=	/var/cache/${PORTNAME}
NETDATA_LOG=	/var/log/${PORTNAME}
NETDATA_PERST=	/var/db/${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-unit-tests
CPPFLAGS+=	-D_WANT_VMMETER
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

OPTIONS_DEFINE=		CLOUD CUPS DBENGINE FREEIPMI GOPLUGIN LTO
OPTIONS_SUB=		YES
OPTIONS_DEFAULT=	DBENGINE
OPTIONS_DEFAULT_FreeBSD_12=	LTO
OPTIONS_DEFAULT_FreeBSD_13=	LTO
OPTIONS_DEFAULT+=	${OPTIONS_DEFAULT_${OPSYS}_${OSREL:R}}

CLOUD_DESC=		Enable cloud functionality
CLOUD_CONFIGURE_OFF=	--disable-cloud
CLOUD_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-web_gui_index.html \
			${FILESDIR}/extra-patch-web_gui_main.js

CUPS_DESC=		Enable support for cups
CUPS_CONFIGURE_ENABLE=	plugin-cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DBENGINE_DESC=			Enable support for database engine
DBENGINE_CONFIGURE_ENABLE=	dbengine
DBENGINE_LIB_DEPENDS=		libJudy.so:devel/judy \
				liblz4.so:archivers/liblz4

FREEIPMI_DESC=			Enable support for freeipmi
FREEIPMI_CONFIGURE_ENABLE=	plugin-freeipmi
FREEIPMI_LIB_DEPENDS=		libfreeipmi.so:sysutils/freeipmi

GOPLUGIN_DESC=		Enable the go collector plugin
GOPLUGIN_RUN_DEPENDS=	${LOCALBASE}/libexec/netdata/plugins.d/god.plugin:net-mgmt/netdata-go

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
	@${REINPLACE_CMD} -e 's|%%PYTHON%%|${PYTHON_CMD}|g' \
	    ${PATCH_WRKSRC}/collectors/python.d.plugin/python.d.plugin.in

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/netdata.conf.sample ${STAGEDIR}${ETCDIR}/netdata.conf.sample
	${MKDIR} ${STAGEDIR}${NETDATA_CACHE}
	${MKDIR} ${STAGEDIR}${NETDATA_LOG}
	${MKDIR} ${STAGEDIR}${NETDATA_PERST}
	(for fi in ${STAGEDIR}${LOCALBASE}/lib/${PORTNAME}/conf.d/*.conf \
			${STAGEDIR}${LOCALBASE}/lib/${PORTNAME}/conf.d/*/*.conf; do \
		${MV} $$fi $$fi".sample"; \
	done)

.include <bsd.port.mk>
