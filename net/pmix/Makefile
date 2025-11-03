PORTNAME=	pmix
DISTVERSION=	5.0.9
CATEGORIES=	net parallel devel
MASTER_SITES=	https://github.com/openpmix/openpmix/releases/download/v${DISTVERSION}/

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	Process Management Interface for Exascale (PMIx)
WWW=		https://openpmix.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	Not supported on 32-bits

LIB_DEPENDS=	libevent.so:devel/libevent \
		libhwloc.so:devel/hwloc2

USES=		gmake libtool localbase:ldflags pathfix pkgconfig tar:bz2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-shared \
		--with-hwloc=${LOCALBASE}

TEST_TARGET=	check
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		BINARIES DOCS IPV6 MUNGE ZLIBNG
OPTIONS_DEFAULT=	BINARIES MUNGE ZLIBNG
OPTIONS_SUB=		yes

BINARIES_DESC=	Build PMIx tools
IPV6_DESC=	Enable IPv6 support
MUNGE_DESC=	Enable authentication via Munge
ZLIBNG_DESC=	Use zlib-ng

BINARIES_CONFIGURE_ENABLE=	pmix-binaries
IPV6_CONFIGURE_ENABLE=		ipv6
MUNGE_LIB_DEPENDS=		libmunge.so:security/munge
MUNGE_CONFIGURE_ON=		--with-munge=${LOCALBASE}
MUNGE_CONFIGURE_OFF=		--without-munge
ZLIBNG_LIB_DEPENDS=		libz-ng.so:archivers/zlib-ng
ZLIBNG_CONFIGURE_ON=		--with-zlibng=${LOCALBASE}
ZLIBNG_CONFIGURE_OFF=		--without-zlibng

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
