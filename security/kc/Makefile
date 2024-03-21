PORTNAME=		kc
PORTVERSION=		2.5.3
PORTREVISION=		1
CATEGORIES=		security

MAINTAINER=		leva@ecentrum.hu
COMMENT=		Console based password storing application
WWW=			https://github.com/levaidaniel/kc

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libxml2.so:textproc/libxml2

CONFLICTS=		kc24

OPTIONS_DEFINE=		PCRE SCRYPT
OPTIONS_DEFAULT=	PCRE SCRYPT LIBEDIT
OPTIONS_RADIO=		CLI
OPTIONS_RADIO_CLI=	LIBEDIT READLINE

SCRYPT_DESC=		Scrypt KDF support (needs libscrypt)

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_MAKE_ENV+=		HAVE_PCRE=yes
SCRYPT_LIB_DEPENDS=	libscrypt.so:security/libscrypt
SCRYPT_MAKE_ENV+=	HAVE_LIBSCRYPT=1
LIBEDIT_USES=		libedit
LIBEDIT_MAKE_ENV+=	EDITLINE=y
READLINE_USES=		readline
READLINE_MAKE_ENV+=	READLINE=y

USES+=			pkgconfig ncurses ssl uidfix
USE_GITHUB=		yes
GH_ACCOUNT=		levaidaniel

PLIST_FILES=		bin/kc share/doc/kc/Changelog.md share/man/man1/kc.1.gz

MAKE_ARGS=		BINDIR="${PREFIX}/bin" \
			MANDIR="${PREFIX}/share/man/man"
MAKE_ENV+=		BUNDLED_BCRYPT=y

post-patch:
	@${REINPLACE_CMD} -e 's|-lncursesw|${NCURSESLIBS}|' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
