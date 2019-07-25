# Created by: Kevin Bowling <kbowling@FreeBSD.org>
# $FreeBSD$

PORTNAME=		ltfs
DISTVERSIONPREFIX=	v
DISTVERSION=		2.4.1.2
DISTVERSIONSUFFIX=	-10254
CATEGORIES=		sysutils

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Reference implementation of LTFS for stand alone tape drive

LICENSE=	BSD3CLAUSE
LICENSE_FILE =	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicudata.so:devel/icu \
		libnetsnmp.so:net-mgmt/net-snmp \
		libpkg.so:ports-mgmt/pkg \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		autoreconf fuse gnome libtool:build pkgconfig ssl

CONFIGURE_ARGS+=	--enable-icu-6x
GH_ACCOUNT=		LinearTapeFileSystem
GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip
USE_GITHUB=		yes
USE_GNOME=		libxml2
USE_LDCONFIG=		yes

post-install:
	@${RM} ${STAGEDIR}${DATADIR}/ltfs
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
