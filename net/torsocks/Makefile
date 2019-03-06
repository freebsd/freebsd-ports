# Created by: Andrei Lavreniyuk <andy.lavr@gmail.com>
# $FreeBSD$

PORTNAME=	torsocks
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	https://people.torproject.org/~dgoulet/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy way to make any app work through Tor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

USES=		alias gmake libtool tar:xz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

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
