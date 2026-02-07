PORTNAME=	lastpass-cli
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/lastpass/lastpass-cli/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LastPass command line interface tool
WWW=		https://lastpass.com/ \
		https://github.com/lastpass/lastpass-cli

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake gnome pkgconfig shebangfix ssl
USE_GNOME=	libxml2

CMAKE_ARGS=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE}
TEST_TARGET=	lpass-test test

PLIST_FILES=	bin/lpass

SHEBANG_FILES=	test/tests

OPTIONS_DEFINE=	BASH MANPAGES PINENTRY XCLIP XSEL
OPTIONS_DEFAULT=BASH MANPAGES
PINENTRY_DESC=	Use pinentry for password entry
XCLIP_DESC=	Use xclip for interacting with X11 clipboard
XSEL_DESC=	Use xsel for interacting with X11 clipboard

BASH_BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion
BASH_PLIST_FILES=	share/bash-completion/completions/lpass
BASH_RUN_DEPENDS=	bash-completion>=0:shells/bash-completion
MANPAGES_ALL_TARGET=	all doc-man
MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc
MANPAGES_INSTALL_TARGET=install install-doc
MANPAGES_PLIST_FILES=	${PREFIX}/share/man/man1/lpass.1.gz
PINENTRY_RUN_DEPENDS=	pinentry:security/pinentry
XCLIP_RUN_DEPENDS=	xclip:x11/xclip
XSEL_RUN_DEPENDS=	xsel:x11/xsel-conrad

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lpass

.include <bsd.port.mk>
