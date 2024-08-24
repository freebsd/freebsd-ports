PORTNAME=	conduit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	net-im
PKGNAMEPREFIX=	matrix-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Simple, fast and reliable chat server powered by Matrix
WWW=		https://conduit.rs/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64le=	compilation failure: called `Option::unwrap()` on a `None` value in ring-0.16.20/build.rs: # see https://gitlab.com/famedly/conduit/-/issues/416
BROKEN_i386=	fails to build

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}
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
GL_TAGNAME=	7a5b8930134cf7ea5ff9880e6fa468b2b3e05c98

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/conduit.toml,${PREFIX}/etc/conduit.toml,' \
		${WRKSRC}/src/main.rs
	@${REINPLACE_CMD} -e 's,/var/lib/conduit,${DBDIR},' \
		${WRKSRC}/conduit-example.toml

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/conduit-example.toml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.toml.sample
	@${MKDIR} ${STAGEDIR}${DBDIR}

.include <bsd.port.mk>
