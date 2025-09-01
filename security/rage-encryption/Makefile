PORTNAME=	rage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.1
PORTREVISION=	6
CATEGORIES=	security
PKGNAMESUFFIX=	-encryption

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple, modern, and secure file encryption tool, using the age format
WWW=		https://github.com/str4d/rage

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libfuse.so:filesystems/fusefs-libs \
		libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	str4d

CARGO_FEATURES=	mount

CONFLICTS=	rage

PLIST_FILES=	bin/rage \
		bin/rage-keygen \
		bin/rage-mount

do-install:
.for f in rage rage-keygen rage-mount
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/${f} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
