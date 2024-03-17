PORTNAME=	gnome-ssh-askpass
PORTVERSION=	6.7p1
CATEGORIES=	security gnome
MASTER_SITES=	OPENBSD/OpenSSH/portable/
DISTNAME=	openssh-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Graphical SSH askpass utility for Gnome2

#LICENSE=      BSD2,BSD3,MIT,public domain,BSD-Style,BEER-WARE,"any purpose with notice intact",ISC-Style
#LICENSE_FILE= ${WRKSRC}/LICENCE

DEPRECATED=	Uses deprecated gtk2 library
EXPIRATION_DATE=	2024-12-31

WRKSRC=		${WRKDIR}/openssh-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/contrib
ALL_TARGET=	gnome-ssh-askpass2

PLIST_FILES=	bin/gnome-ssh-askpass2
USES=		gnome pkgconfig
USE_GNOME=	gtk20

CFLAGS+=	-lpthread

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gnome-ssh-askpass2 \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
