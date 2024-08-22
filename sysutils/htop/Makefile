PORTNAME=	htop
DISTVERSION=	3.3.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}-dev/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	gaod@hychen.org
COMMENT=	Better top(1) - interactive process viewer
WWW=		https://htop.dev/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils ncurses tar:xz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-unicode

PLIST_FILES=	bin/htop \
		share/man/man1/htop.1.gz \
		share/applications/htop.desktop \
		share/icons/hicolor/scalable/apps/htop.svg \
		share/pixmaps/htop.png

OPTIONS_DEFINE=	LSOF

LSOF_RUN_DEPENDS=	lsof:sysutils/lsof

.include <bsd.port.mk>
