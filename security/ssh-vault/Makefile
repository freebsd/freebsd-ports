PORTNAME=	ssh-vault
DISTVERSION=	1.3.9
CATEGORIES=	security
MASTER_SITES=	CRATESIO/${PORTNAME}/${DISTNAME}${CARGO_CRATE_EXT}
DISTFILES+=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	nbari@tequila.io
COMMENT=	Encrypt/decrypt using ssh keys
WWW=		https://ssh-vault.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

PLIST_FILES=	bin/ssh-vault

.include <bsd.port.mk>
