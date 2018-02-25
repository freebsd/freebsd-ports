# Created by: Andrei Lavreniyuk <andy.lavr@gmail.com>
# $FreeBSD$

PORTNAME=	torsocks
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy way to make any app work through Tor

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	dgoulet

GNU_CONFIGURE=	yes
USES=		alias autoreconf gmake libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

PORTDOCS=	ChangeLog DEBUG SOCKS5 socks-extensions.txt

OPTIONS_DEFINE=	DOCS

post-build:
	@${ECHO}
	@${ECHO} "Please run 'make check' (requires bash)."
	@${ECHO} "One testcase is known to fail."
	@${ECHO}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/tor/torsocks.conf ${STAGEDIR}${PREFIX}/etc/tor/torsocks.conf.sample

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.mk>
