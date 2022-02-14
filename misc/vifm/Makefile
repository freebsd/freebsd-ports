# Created by: Stefan Walter <swalter@lettermax.de>

PORTNAME=	vifm
PORTVERSION=	0.12
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	mp39590@gmail.com
COMMENT=	Ncurses based file manager with vi like keybindings

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils gmake ncurses shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gtk

SHEBANG_FILES=	data/vifm-media data/vifm-media-osx

USE_GITHUB=	yes

CFLAGS+=	-fcommon

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
