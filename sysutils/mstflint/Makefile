PORTNAME=	mstflint
DISTVERSIONPREFIX=	v
DISTVERSION=	4.18.0-1
CATEGORIES=	sysutils

MAINTAINER=	hselasky@FreeBSD.org
COMMENT?=	Firmware Burning and Diagnostics Tools for Mellanox devices

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE

USES=		autoreconf libtool gmake pkgconfig

OPTIONS_DEFINE=	FWMANAGER ADAB STATIC
OPTIONS_SUB=	yes

.if defined(LITE)
OPTIONS_SLAVE=	FWMANAGER ADAB STATIC
.endif

FWMANAGER_DESC=	Build with mstfwmanager and mstarchive
ADAB_DESC=	Build with mstreg and mstlink
STATIC_DESC=	Static binary (disable curl support)
STATIC_CONFIGURE_ON=	--enable-all-static --disable-dc \
			--disable-openssl --disable-inband

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Mellanox

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
.else
USES+=	ssl
.endif

.if ${PORT_OPTIONS:MADAB}
CONFIGURE_ARGS+=	--enable-adb-generic-tools
.if ${PORT_OPTIONS:MSTATIC}
BROKEN=		does not link: expat2 no longer provides static library
BUILD_DEPENDS+=	xmlwf:textproc/expat2 \
		boost-libs>0:devel/boost-libs
.else
LIB_DEPENDS+=	libexpat.so:textproc/expat2 \
		libboost_regex.so:devel/boost-libs
.endif
.endif

.if ${PORT_OPTIONS:MFWMANAGER}
CONFIGURE_ARGS+=	--enable-fw-mgr
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	xmllint:textproc/libxml2 \
		${LOCALBASE}/include/boost/algorithm/string/detail/formatter_regex.hpp:devel/boost-libs
EXTRA_PATCHES+=	${PATCHDIR}/extrat-patch-configure.ac \
		${PATCHDIR}/extrat-patch-mlxarchive_Makefile.am \
		${PATCHDIR}/extrat-patch-mlxarchive_mlxarchive_mfa2.cpp \
		${PATCHDIR}/extrat-patch-mlxfwupdate_Makefile.am \
		${PATCHDIR}/extrat-patch-mlxfwupdate_server_request.cpp
.else
LIB_DEPENDS+=	libxml2.so:textproc/libxml2 \
		libboost_regex.so:devel/boost-libs \
		libcurl.so:ftp/curl
RUN_DEPENDS+=	ca_root_nss>=0:security/ca_root_nss
.endif
.endif

.if defined(LITE)
LDFLAGS+=	-lmd
EXTRA_PATCHES+=	${PATCHDIR}/extrat-LITE-patch-Makefile.am \
		${PATCHDIR}/extrat-LITE-patch-mlxconfig_Makefile.am \
		${PATCHDIR}/extrat-LITE-patch-mlxreg_Makefile.am \
		${PATCHDIR}/extrat-LITE-patch-cmdif_Makefile.am \
		${PATCHDIR}/extrat-LITE-patch-mtcr_freebsd_Makefile.am \
		${PATCHDIR}/extrat-LITE-patch-tools_layouts_Makefile.am \
		${PATCHDIR}/extrat-LITE-patch-common_Makefile.am \
		${PATCHDIR}/extrat-LITE-patch-dev_mgt_Makefile.am \
		${PATCHDIR}/extrat-LITE-patch-reg_access_Makefile.am
post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libadb_parser.a \
	${STAGEDIR}${PREFIX}/lib/libcmdif.a \
	${STAGEDIR}${PREFIX}/lib/libdev_mgt.a \
	${STAGEDIR}${PREFIX}/lib/libmodules_lib.a \
	${STAGEDIR}${PREFIX}/lib/libmstreg_lib.a \
	${STAGEDIR}${PREFIX}/lib/libprint_util_lib.a \
	${STAGEDIR}${PREFIX}/lib/libreg_access.a \
	${STAGEDIR}${PREFIX}/lib/libtools_layouts.a \
	${STAGEDIR}${PREFIX}/lib/libmstarchive.a \
	${STAGEDIR}${PREFIX}/lib/mstflint/libmtcr_ul.a \
	${STAGEDIR}${PREFIX}/bin/mstarchive
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/mstflint
.else
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/rreg_access.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/ccmdif.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/cmtcr.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/c_dev_mgt.so
.endif
.include <bsd.port.mk>
