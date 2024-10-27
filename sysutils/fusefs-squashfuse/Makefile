PORTNAME=	squashfuse
DISTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/vasi/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Mount a squashfs archive and treat it like a local file system
WWW=		https://github.com/vasi/squashfuse

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblzo2.so:archivers/lzo2 \
		liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd

USES=		fuse:3 libtool localbase:ldflags pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-static \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
