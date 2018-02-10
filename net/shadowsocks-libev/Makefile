# Created by: Xiaoding Liu <xiaoding+freebsd@xiaoding.org>
# $FreeBSD$

PORTNAME=	shadowsocks-libev
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.3
CATEGORIES=	net

MAINTAINER=	xiaoding+freebsd@xiaoding.org
COMMENT=	Lightweight tunnel proxy which can help you get through firewalls

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libev.so:devel/libev \
		libmbedcrypto.so:security/mbedtls \
		libpcre.so:devel/pcre \
		libsodium.so:security/libsodium \
		libcares.so:dns/c-ares

USES=		autoreconf gmake libtool:keepla pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_GITHUB=	yes
GH_ACCOUNT=	shadowsocks
GH_TUPLE=	shadowsocks:libbloom:7a9deb8:libbloom/libbloom \
		shadowsocks:libcork:0220aa5:libcork/libcork \
		shadowsocks:ipset:3ea7fe3:libipset/libipset
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	BASH DOCS ZSH
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto
DOCS_CONFIGURE_OFF=	--disable-documentation

USE_RC_SUBR=	shadowsocks_libev

post-patch:
	@${REINPLACE_CMD} -e 's|^#ifdef TCP_FASTOPEN|#if defined(TCP_FASTOPEN) \&\& defined(__linux)|' \
		${WRKSRC}/src/local.c ${WRKSRC}/src/server.c

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/config.json ${STAGEDIR}${ETCDIR}/config.json.sample

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
.for c in ss-local ss-manager ss-redir ss-server ss-tunnel
	${INSTALL_DATA} ${WRKSRC}/completions/bash/${c} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/${c}
.endfor

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
.for c in _ss-local _ss-manager _ss-redir _ss-server _ss-tunnel
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/${c} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/${c}
.endfor

.include <bsd.port.mk>
