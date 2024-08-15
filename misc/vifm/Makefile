PORTNAME=	vifm
PORTVERSION=	0.13
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Ncurses based file manager with vi like keybindings
WWW=		https://vifm.info/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils gmake ncurses perl5 shebangfix
USE_GITHUB=	yes
USE_PERL5=	build
SHEBANG_FILES=	data/vifm-media data/vifm-media-osx

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gtk
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
