PORTNAME=	mstflint
DISTVERSIONPREFIX=	v
DISTVERSION=	4.25.0-1
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Firmware Burning and Diagnostics Tools for Mellanox devices
WWW=		https://github.com/Mellanox/mstflint

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool localbase:ldflags pkgconfig ssl
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	Mellanox

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=	FWMANAGER ADAB
OPTIONS_SUB=	yes

ADAB_DESC=	Build with mstreg and mstlink
FWMANAGER_DESC=	Build with mstfwmanager and mstarchive
STATIC_DESC=	Static binary (disable curl support)

ADAB_CONFIGURE_ON=	--enable-adb-generic-tools
ADAB_BUILD_DEPENDS=	${LOCALBASE}/lib/libboost_regex.a:devel/boost-libs
ADAB_LIB_DEPENDS=	libexpat.so:textproc/expat2

FWMANAGER_CONFIGURE_ON=	--enable-fw-mgr
FWMANAGER_BUILD_DEPENDS=	${LOCALBASE}/lib/libboost_regex.a:devel/boost-libs
FWMANAGER_LIB_DEPENDS=	libcurl.so:ftp/curl \
						libxml2.so.2:textproc/libxml2

post-patch:
	@${ECHO} '#define TOOLS_GIT_SHA "N/A"' >  ${WRKSRC}/common/gitversion.h
	@${MKDIR} ${WRKSRC}/config
	# ADAB and FWMANAGER options depends of libboost, so statically link this
	# lib to avoid installing 220MB of lib dependency.
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/mlxlink/Makefile.am \
		${WRKSRC}/mlxarchive/Makefile.am \
		${WRKSRC}/mlxreg/Makefile.am

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/rreg_access.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/ccmdif.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/cmtcr.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/c_dev_mgt.so

.include <bsd.port.mk>
