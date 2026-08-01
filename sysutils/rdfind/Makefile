PORTNAME=	rdfind
DISTVERSION=	1.8.0
CATEGORIES=	sysutils
MASTER_SITES=	https://rdfind.pauldreik.se/

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Utility to find duplicate files based on their content
WWW=		https://rdfind.pauldreik.se/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnettle.so:security/nettle

USES=		compiler:c++17-lang localbase:ldflags
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	XXHASH
OPTIONS_DEFAULT=XXHASH

XXHASH_DESC=		Enable support for faster xxhash128 checksum
XXHASH_BUILD_DEPENDS=	xxhash>0:devel/xxhash
XXHASH_RUN_DEPENDS=	xxhash>0:devel/xxhash
XXHASH_CONFIGURE_WITH=	xxhash

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
