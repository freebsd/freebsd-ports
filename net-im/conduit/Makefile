PORTNAME=	conduit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.8
CATEGORIES=	net-im
PKGNAMEPREFIX=	matrix-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Simple, fast and reliable chat server powered by Matrix
WWW=		https://conduit.rs/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	librocksdb.so:databases/rocksdb
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cargo gmake
USE_RC_SUBR=	${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${USERS}
SUBS=		DBDIR=${DBDIR} \
		USERS=${USERS} \
		GROUPS=${GROUPS} \
		PORTNAME=${PORTNAME}
PLIST_SUB=	${SUBS}
SUB_LIST=	${SUBS}
SUB_FILES=	pkg-message pkg-install
DBDIR=		/var/db/${PORTNAME}

USE_GITLAB=	yes
GL_ACCOUNT=	famedly
GL_TAGNAME=	9bba85c7e532b99358d18df200be93bb2ccc9a63

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/conduit.toml,${PREFIX}/etc/conduit.toml,' \
		${WRKSRC}/src/main.rs
	@${REINPLACE_CMD} -e 's,/var/lib/matrix-conduit,${DBDIR},' \
		${WRKSRC}/conduit-example.toml

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/conduit-example.toml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.toml.sample
	@${MKDIR} ${STAGEDIR}${DBDIR}

.include <bsd.port.post.mk>
