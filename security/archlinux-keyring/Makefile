PORTNAME=	archlinux-keyring
DISTVERSION=	20231222
CATEGORIES=	security

PATCH_SITES=	${WWW}/-/commit/
PATCHFILES=	d1bc77b5684725489a2c91a32bf67d7d88b85250.patch:-p1 \
		6340544b465e368a15c9b49156408b0ed2ab78fb.patch:-p1 # https://gitlab.archlinux.org/archlinux/archlinux-keyring/-/merge_requests/280

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Arch Linux PGP keyring
WWW=		https://gitlab.archlinux.org/archlinux/archlinux-keyring/

LICENSE=	GPLv3+

BUILD_DEPENDS=	sq:security/sequoia-sq \
		ginstall:sysutils/coreutils \
		bash:shells/bash
RUN_DEPENDS=	bash:shells/bash \
		pacman-key:sysutils/pacman@archlinux

USES=		gmake pkgconfig python:3.10+ shebangfix trigger
SHEBANG_FILES=	keyringctl wkd_sync
BINARY_ALIAS=	install=ginstall

USE_GITLAB=	yes
GL_SITE=	https://gitlab.archlinux.org
GL_ACCOUNT=	archlinux
GL_TAGNAME=	16641e2d1c39ba4bb73b900bc3ee58472a29c8b0

NO_ARCH=	yes

PLIST_FILES=	share/pacman/keyrings/archlinux-revoked \
		share/pacman/keyrings/archlinux-trusted \
		share/pacman/keyrings/archlinux.gpg

post-patch:
	@${REINPLACE_CMD} -e 's|/bin|$(PREFIX)/bin|' ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pacman/keyrings

.include <bsd.port.mk>
