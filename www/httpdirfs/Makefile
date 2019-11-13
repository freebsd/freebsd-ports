# $FreeBSD$

PORTNAME=	httpdirfs
DISTVERSION=	1.2.0
CATEGORIES=	www

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	FUSE filesystem to mount HTTP directory listings, with a permanent cache

LICENSE=	GPL3OPENSSL
LICENSE_NAME=	GPLv3 or later with execption to link with OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfuse.so:sysutils/fusefs-libs \
		libgumbo.so:devel/gumbo \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		gmake localbase pkgconfig ssl
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	fangfufu

MAKE_ENV=	prefix=${PREFIX}

PLIST_FILES=	bin/httpdirfs \
		man/man1/httpdirfs.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/httpdirfs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
