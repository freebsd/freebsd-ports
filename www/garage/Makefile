PORTNAME=	garage
DISTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://git.deuxfleurs.fr/Deuxfleurs/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Open-source distributed storage service
WWW=		https://garagehq.deuxfleurs.fr/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libsodium.so:security/libsodium \
		libzstd.so:archivers/zstd

USES=		cargo pkgconfig
CARGO_ENV+=	SODIUM_USE_PKG_CONFIG=1
CARGO_INSTALL_PATH=	src/garage
SUB_FILES=	pkg-message
USE_RC_SUBR=	garage
CARGO_VENDOR_DIR=	${WRKDIR}/cargo-crates
CARGO_FEATURES=	syslog

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH:Marmv?} || ${MACHINE_ARCH} == i386
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-extract:
	${MV} -v ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	${GREP} -F -Rl /etc/garage ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's,/etc/garage,${ETCDIR},g'

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name *\.bak"

.include <bsd.port.post.mk>
