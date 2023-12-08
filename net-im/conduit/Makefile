PORTNAME=	conduit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	net-im
PKGNAMEPREFIX=	matrix-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Simple, fast and reliable chat server powered by Matrix
WWW=		https://conduit.rs/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}

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
GL_TAGNAME=	0c2cfda3ae923d9e922d5edf379e4d8976a52d4e

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/conduit.toml,${PREFIX}/etc/conduit.toml,' \
		${WRKSRC}/src/main.rs
	@${REINPLACE_CMD} -e 's,/var/lib/conduit,${DBDIR},' \
		${WRKSRC}/conduit-example.toml

post-install:
	${INSTALL_DATA} ${WRKSRC}/conduit-example.toml ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.toml.sample
	@${MKDIR} ${STAGEDIR}${DBDIR}

.include <bsd.port.mk>
