# Created by: LEVAI Daniel <leva@ecentrum.hu>
# $FreeBSD$

PORTNAME=		kc
PORTVERSION=		2.4.2
PORTREVISION=	1
CATEGORIES=		security
PKGNAMESUFFIX=		24

MAINTAINER=		leva@ecentrum.hu
COMMENT=		Console based password storing application

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libxml2.so:textproc/libxml2

CONFLICTS=		kc

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

PLIST_FILES=		bin/kc man/man1/kc.1.gz

MAKE_ENV+=		BUNDLED_BCRYPT=y

post-patch:
	@${REINPLACE_CMD} -e 's|-lncursesw|-l${NCURSES_IMPL}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
