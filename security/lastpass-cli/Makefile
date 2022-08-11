PORTNAME=	lastpass-cli
PORTVERSION=	1.3.3
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	tom@hur.st
COMMENT=	LastPass command line interface tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake:noninja gnome pkgconfig ssl
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	lastpass

TEST_TARGET=	lpass-test test

PLIST_FILES=	bin/lpass

OPTIONS_DEFINE=		BASH MANPAGES PINENTRY XCLIP XSEL
OPTIONS_DEFAULT=	BASH MANPAGES
PINENTRY_DESC=		Use pinentry for password entry
XCLIP_DESC=		Use xclip for interacting with X11 clipboard
XSEL_DESC=		Use xsel for interacting with X11 clipboard

BASH_BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion
BASH_RUN_DEPENDS=	bash-completion>=0:shells/bash-completion
BASH_PLIST_FILES=	share/bash-completion/completions/lpass
MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
MANPAGES_ALL_TARGET=	all doc-man
MANPAGES_INSTALL_TARGET=install install-doc
MANPAGES_PLIST_FILES=	${MANPREFIX}/share/man/man1/lpass.1.gz

PINENTRY_RUN_DEPENDS=	pinentry:security/pinentry
XCLIP_RUN_DEPENDS=	xclip:x11/xclip
XSEL_RUN_DEPENDS=	xsel:x11/xsel-conrad

post-extract:
	@${REINPLACE_CMD} -e 's/-Wno-language-extension-token//g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/build\/lpass-test/lpass-test/' \
		${WRKSRC}/test/include.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lpass

.include <bsd.port.mk>
