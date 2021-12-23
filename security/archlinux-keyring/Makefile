PORTNAME=	archlinux-keyring
DISTVERSION=	20211028
CATEGORIES=	security
MASTER_SITES=	https://sources.archlinux.org/other/${PORTNAME}/

MAINTAINER=	vishwin@vishwin.info
COMMENT=	Arch Linux PGP keyring

LICENSE=	GPLv2+

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	share/pacman/keyrings/archlinux-revoked \
		share/pacman/keyrings/archlinux-trusted \
		share/pacman/keyrings/archlinux.gpg

.include <bsd.port.mk>
