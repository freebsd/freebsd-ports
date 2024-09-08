PORTNAME=	gpg-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
PORTREVISION=	5
CATEGORIES=	security

MAINTAINER=	se@FreeBSD.org
COMMENT=	Terminal User Interface for GnuPG
WWW=		https://github.com/orhun/gpg-tui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gpgme>=1.7.0:security/gpgme
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libxcb.so:x11/libxcb \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	gpg:security/gnupg \
		gpgme>=1.7.0:security/gpgme

USES=		cargo python:build
USE_GITHUB=	yes
GH_ACCOUNT=	orhun

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/gpg-tui \
		bin/gpg-tui-completions \
		share/man/man1/gpg-tui.1.gz

post-install:
		${INSTALL_DATA} ${WRKSRC}/man/gpg-tui.1 ${STAGEDIR}${PREFIX}/share/man/man1/
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gpg-tui-completions
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gpg-tui

.include <bsd.port.mk>
