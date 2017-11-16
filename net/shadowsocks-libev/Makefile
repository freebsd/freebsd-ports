# Created by: Xiaoding Liu <xiaoding+freebsd@xiaoding.org>
# $FreeBSD$

PORTNAME=	shadowsocks-libev
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	xiaoding+freebsd@xiaoding.org
COMMENT=	Lightweight tunnel proxy which can help you get through firewalls

LICENSE=	GPLv3

LIB_DEPENDS=	libev.so:devel/libev \
		libmbedcrypto.so:security/mbedtls \
		libpcre.so:devel/pcre \
		libsodium.so:security/libsodium \
		libcares.so:dns/c-ares

USES=		autoreconf gmake libtool:keepla pathfix

# fetch from github repo
USE_GITHUB=	yes
GH_ACCOUNT=	shadowsocks
GH_TUPLE=	shadowsocks:libcork:0220aa5:libcork/libcork \
		shadowsocks:ipset:3ea7fe3:libipset/libipset \
		shadowsocks:libbloom:7a9deb8:libbloom/libbloom

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto
DOCS_CONFIGURE_OFF=	--disable-documentation

USE_RC_SUBR=	shadowsocks_libev

post-patch:
	${REINPLACE_CMD} -e 's|^#ifdef TCP_FASTOPEN|#if defined(TCP_FASTOPEN) \&\& defined(__linux)|' \
		${WRKSRC}/src/local.c ${WRKSRC}/src/server.c

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/config.json ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
