# Created by: Xiaoding Liu <xiaoding+freebsd@xiaoding.org>
# $FreeBSD$

PORTNAME=	shadowsocks-libev
PORTVERSION=	1.6.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	xiaoding+freebsd@xiaoding.org
COMMENT=	Lightweight tunnel proxy which can help you get through firewalls

LICENSE=	GPLv3

# fetch from github repo
USE_GITHUB=	yes
GH_ACCOUNT=	madeye

GNU_CONFIGURE=	yes
USES=		gmake libtool:keepla pathfix ssl
CPPFLAGS+=	-I${OPENSSLINC}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}

# Help solve building error since the integrated libsodium enables this option.
CFLAGS+=	-fstack-protector

USE_RC_SUBR=	shadowsocks_libev

post-patch:
	${REINPLACE_CMD} -e 's|^#ifdef TCP_FASTOPEN|#if defined(TCP_FASTOPEN) \&\& defined(__linux)|' \
		${WRKSRC}/src/local.c ${WRKSRC}/src/server.c

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} ${WRKSRC}/debian/config.json  ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
