PORTNAME=	tinyfugue
PORTVERSION=	5.2.1
PORTREVISION=	0
CATEGORIES=	net games
PKGNAMESUFFIX=	-devel${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Popular programmable MUD client, with macro support and more
WWW=		https://github.com/ingwarsw/tinyfugue

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USE_GITHUB=	yes
GH_ACCOUNT=	ingwarsw

USES=		ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-manpage --enable-version --enable-symlink=no \
		--exec-prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--mandir=${PREFIX}/share/man \
		--datadir=${PREFIX}/lib --with-inclibpfx=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}
PLIST_SUB=	DISTNAME=tf-development

OPTIONS_DEFINE=	ATCP GMCP WIDECHAR LUA PYTHON
OPTIONS_DEFAULT=	ATCP GMCP WIDECHAR LUA

ATCP_DESC=	telnet ATCP support
ATCP_CONFIGURE_ENABLE=	atcp
GMCP_DESC=	telnet GMCP support
GMCP_CONFIGURE_ENABLE=	gmcp
WIDECHAR_CONFIGURE_ENABLE=	widechar
WIDECHAR_LIB_DEPENDS=	libicuuc.so:devel/icu
LUA_USES=		lua
LUA_CONFIGURE_ENABLE=	lua
PYTHON_USES=		python gettext-runtime
PYTHON_CONFIGURE_ENABLE=	python

post-build:
	${STRIP_CMD} ${WRKSRC}/src/tf

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/tf.1.nroffman \
		${STAGEDIR}${PREFIX}/share/man/man1/tf-development.1

.include <bsd.port.mk>
