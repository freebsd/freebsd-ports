PORTNAME=	garage
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://git.deuxfleurs.fr/Deuxfleurs/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Open-source distributed storage service
WWW=		https://garagehq.deuxfleurs.fr/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libsodium.so:security/libsodium \
		libzstd.so:archivers/zstd

USES=		cargo pkgconfig
USE_RC_SUBR=	garage

CARGO_FEATURES=		syslog
CARGO_INSTALL_PATH=	src/garage
CARGO_ENV+=		SODIUM_USE_PKG_CONFIG=1
CARGO_VENDOR_DIR=	${WRKDIR}/cargo-crates

SUB_FILES=	garage.toml pkg-message
SUB_LIST=	DBDIR=${DBDIR} GROUP=${GARAGE_GROUP} USER=${GARAGE_USER}

USERS=		${GARAGE_USER}
GROUPS=		${GARAGE_GROUP}

PLIST_SUB=	GROUP=${GARAGE_GROUP} \
		USER=${GARAGE_USER}

OPTIONS_DEFINE=	DOCS

DBDIR=		/var/db/${PORTNAME}
GARAGE_USER=	${PORTNAME}
GARAGE_GROUP=	${GARAGE_USER}

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name *.bak"

post-install:
	@${MKDIR} ${STAGEDIR}${DBDIR}
	${INSTALL_DATA} ${WRKDIR}/garage.toml ${STAGEDIR}${PREFIX}/etc/garage.toml.sample

.include <bsd.port.post.mk>
