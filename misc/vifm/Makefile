PORTNAME=	vifm
PORTVERSION=	0.13
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Ncurses based file manager with vi like keybindings
WWW=		https://vifm.info/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils gmake ncurses shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	data/vifm-media data/vifm-media-osx

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--without-gtk

CFLAGS+=	-fcommon

OPTIONS_DEFINE=		DOCS
# dependency to generate help tags
DOCS_BUILD_DEPENDS=	vim:editors/vim

.include <bsd.port.mk>
