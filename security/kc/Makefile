PORTNAME=	kc
DISTVERSION=	2.5.3
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	leva@ecentrum.hu
COMMENT=	Console based password storing application
WWW=		https://github.com/levaidaniel/kc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash

USES=		gnome ncurses pkgconfig ssl uidfix
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	levaidaniel

MAKE_ARGS=	BINDIR="${PREFIX}/bin" \
		MANDIR="${PREFIX}/share/man/man"
MAKE_ENV=	BUNDLED_BCRYPT=y
TEST_ENV=	SH=${PREFIX}/bin/bash
TEST_TARGET=	test

CONFLICTS=	kc24

PLIST_FILES=	bin/kc share/doc/kc/Changelog.md share/man/man1/kc.1.gz

OPTIONS_DEFINE=		SCRYPT YUBIKEY
OPTIONS_DEFAULT=	LIBEDIT SCRYPT
OPTIONS_SINGLE=		CLI
OPTIONS_SINGLE_CLI=	LIBEDIT READLINE

SCRYPT_DESC=	Scrypt KDF support (needs libscrypt)
YUBIKEY_DESC=	YubiKey support (needs libyubikey and ykpers)

LIBEDIT_USES=		libedit
LIBEDIT_MAKE_ENV=	EDITLINE=y
READLINE_USES=		readline
READLINE_MAKE_ENV=	READLINE=y
SCRYPT_LIB_DEPENDS=	libscrypt.so:security/libscrypt
SCRYPT_MAKE_ENV=	HAVE_LIBSCRYPT=1
YUBIKEY_LIB_DEPENDS=	libykpers-1.so:security/ykpers \
			libyubikey.so:security/libyubikey
YUBIKEY_MAKE_ENV+=	CFLAGS=-I${PREFIX}/include \
			HAVE_YUBIKEY=y

post-patch:
	@${REINPLACE_CMD} -e 's|-lncursesw|${NCURSESLIBS}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^#!/bin/sh|#!${PREFIX}/bin/bash|' ${WRKSRC}/regress/run_tests.sh

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
