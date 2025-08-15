PORTNAME=	mstflint
DISTVERSIONPREFIX=	v
DISTVERSION=	4.33.0-1
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
ADAB_LIB_DEPENDS=	libexpat.so:textproc/expat2

FWMANAGER_CONFIGURE_ON=	--enable-fw-mgr
FWMANAGER_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libxml2.so:textproc/libxml2

post-patch:
	@${ECHO} '#define TOOLS_GIT_SHA "N/A"' >  ${WRKSRC}/common/gitversion.h
	@${MKDIR} ${WRKSRC}/config

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/rreg_access.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/ccmdif.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/cmtcr.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/python_tools/c_dev_mgt.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mstflint/sdk/libresource_dump_sdk.so

.include <bsd.port.mk>
