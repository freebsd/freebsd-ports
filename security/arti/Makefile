PORTNAME=	arti
DISTVERSION=	1.4.6
CATEGORIES=	security

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Implementation of Tor, in Rust
WWW=		https://tpo.pages.torproject.net/core/arti/

LICENSE=	MIT

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=Zeroize crate does not support i386
LIB_DEPENDS=	libzstd.so:archivers/zstd

FLAVORS=	default full
full_PKGNAMESUFFIX=	-full
USES=		cargo sqlite ssl llvm
USE_RC_SUBR=	arti
GROUPS=		_arti
USERS=		_arti
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"
USE_GITLAB=	yes
GL_SITE=	https://gitlab.torproject.org
GL_ACCOUNT=	tpo/core
GL_TAGNAME=	35ecc0896dfcea19692004341a0d5c3a5167e142
CARGO_INSTALL=	no
default_DESCR=	${.CURDIR}/pkg-descr
full_DESCR=	${.CURDIR}/pkg-descr-full
.if ${FLAVOR:U} != full
CARGO_FEATURES=	default
.endif
.if ${FLAVOR:U} == full
CARGO_FEATURES=	full
.endif

OPTIONS_DEFINE=	RUSTLS

RUSTLS_VARS=	CARGO_FEATURES+=rustls
RUSTLS_DESC=	Use rustls instead of openssl

do-install:
	${INSTALL_SCRIPT} ${CARGO_TARGET_DIR}/*/arti ${STAGEDIR}${PREFIX}/bin/arti

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/log/arti ${STAGEDIR}/var/run/arti ${STAGEDIR}/var/db/arti
	${INSTALL_DATA} ${WRKSRC}/crates/arti/src/arti-example-config.toml ${STAGEDIR}${ETCDIR}/arti.toml.sample

.include <bsd.port.mk>
