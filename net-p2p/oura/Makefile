PORTNAME=		oura
DISTVERSIONPREFIX=	v
DISTVERSION=		1.8.4
PORTREVISION=	14
CATEGORIES=		net-p2p

MAINTAINER=		boris@zfs.ninja
COMMENT=		A pipeline that connects to the tip of a Cardano node
WWW=			https://txpipe.github.io/oura/

LICENSE=		APACHE20

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	requires AVX on x86

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	txpipe

USE_RC_SUBR=	oura

PLIST_FILES=	bin/oura

post-patch:
		# Remove vendored ssl
		${REINPLACE_CMD} -e 's/^openssl.*/openssl = { version = "0.10", optional = true }/g' \
		${WRKSRC}/Cargo.toml

.include <bsd.port.mk>
