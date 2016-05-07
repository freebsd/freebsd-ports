# $FreeBSD$

PORTNAME=		fastd
PORTVERSION=		18.a.20151111
PORTREVISION=		2
CATEGORIES=		security net
MASTER_SITES=		https://git.universe-factory.net/fastd/snapshot/
PKGNAMESUFFIX=		-devel
DISTNAME=		999b87b80302dbc14e23ef3dff187b91dae7fab5

MAINTAINER=		crest_maintainer@rlwinm.de
COMMENT=		Fast and Secure Tunnelling Daemon

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/COPYRIGHT

LIB_DEPENDS=		libjson-c.so:devel/json-c       \
			libsodium.so:security/libsodium \
			libuecc.so:security/libuecc

USES=			bison cmake:outsource pkgconfig tar

PKG_CONFIG_PATH=	${PREFIX}/lib/pkgconfig/
CONFIGURE_ENV+=		PKG_CONFIG_PATH=${PKG_CONFIG_PATH}

USE_RC_SUBR=		fastd_devel

PLIST_FILES=		bin/fastd-devel           \
			man/man1/fastd-devel.1.gz

.include <bsd.port.pre.mk>

# GCC from base does not support -mpclmul.
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000024
CMAKE_ARGS+=		-DWITH_MAC_GHASH_PCLMULQDQ=FALSE
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fastd.1 ${STAGEDIR}${PREFIX}/man/man1/fastd-devel.1

.include <bsd.port.post.mk>
