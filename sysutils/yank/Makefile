PORTNAME=	yank
DISTVERSION=	1.3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/mptre/yank/releases/download/v${DISTVERSION}/

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Yank terminal output to clipboard
WWW=		https://github.com/mptre/yank/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	MANPREFIX=${PREFIX}/man \
		PREFIX=${PREFIX}
PLIST_FILES=	bin/yank \
		man/man1/yank.1.gz

OPTIONS_DEFINE=		CLIPBOARD
OPTIONS_DEFAULT=	CLIPBOARD

CLIPBOARD_DESC=		Clipboard support
CLIPBOARD_RUN_DEPENDS=	xsel-conrad>=0:x11/xsel-conrad

.include <bsd.port.mk>
