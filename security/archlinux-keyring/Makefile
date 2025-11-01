PORTNAME=	archlinux-keyring
DISTVERSION=	20250430.1
CATEGORIES=	security

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Arch Linux PGP keyring
WWW=		https://gitlab.archlinux.org/archlinux/archlinux-keyring/

LICENSE=	GPLv3+

BUILD_DEPENDS=	sq:security/sequoia-sq \
		ginstall:sysutils/coreutils \
		bash:shells/bash
RUN_DEPENDS=	bash:shells/bash \
		pacman-key:sysutils/pacman@archlinux

USES=		gmake pkgconfig python shebangfix trigger
SHEBANG_FILES=	keyringctl wkd_sync
BINARY_ALIAS=	install=ginstall

USE_GITLAB=	yes
GL_SITE=	https://gitlab.archlinux.org
GL_ACCOUNT=	archlinux

NO_ARCH=	yes

PLIST_FILES=	share/pacman/keyrings/archlinux-revoked \
		share/pacman/keyrings/archlinux-trusted \
		share/pacman/keyrings/archlinux.gpg

post-patch:
	@${REINPLACE_CMD} -e 's|/bin|$(PREFIX)/bin|' ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pacman/keyrings

.include <bsd.port.mk>
