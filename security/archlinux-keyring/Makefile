PORTNAME=	archlinux-keyring
DISTVERSION=	20251116
CATEGORIES=	security

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Arch Linux PGP keyring
WWW=		https://gitlab.archlinux.org/archlinux/archlinux-keyring/

LICENSE=	GPLv3+

BUILD_DEPENDS=	sq:security/sequoia-sq \
		voa:security/voa \
		ginstall:sysutils/coreutils \
		bash:shells/bash
RUN_DEPENDS=	bash:shells/bash \
		pacman-key:sysutils/pacman@archlinux

USES=		gmake pkgconfig python shebangfix trigger
SHEBANG_FILES=	keyringctl wkd_sync
BINARY_ALIAS=	install=ginstall \
		ln=gln \
		mkdir=gmkdir

USE_GITLAB=	yes
GL_SITE=	https://gitlab.archlinux.org
GL_ACCOUNT=	archlinux

NO_ARCH=	yes
ALL_TARGET=	build build-voa
INSTALL_TARGET=	install install-voa

post-patch:
	@${REINPLACE_CMD} -e 's|/bin|$(PREFIX)/bin|' ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pacman/keyrings

.include <bsd.port.mk>
