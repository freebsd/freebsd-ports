PORTNAME=	httpdirfs
DISTVERSION=	1.2.6
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

PATCH_SITES=	https://github.com/fangfufu/httpdirfs/commit/
PATCHFILES=	43bdf7e71fde43084519e86051533a6b20c31474.patch:-p1 \
		08700415d7b61d9f611a858481b26858fe92eb7a.patch:-p1

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	FUSE filesystem to mount HTTP directory listings, with a permanent cache
WWW=		https://github.com/fangfufu/httpdirfs

LICENSE=	GPL3OPENSSL
LICENSE_NAME=	GPLv3 or later with execption to link with OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgumbo.so:devel/gumbo \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		fuse:3 meson pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	fangfufu

PLIST_FILES=	bin/httpdirfs
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
