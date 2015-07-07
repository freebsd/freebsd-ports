# Created by: Andrei Lavreniyuk <andy.lavr@gmail.com>
# $FreeBSD$

PORTNAME=	torsocks
PORTVERSION=	2.0.0
CATEGORIES=	net security
MASTER_SITES=	GH
DISTNAME=	${GH_ACCOUNT}-${PORTNAME}-${GH_TAGNAME}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Easy way to make any app work through Tor

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	dgoulet
GH_PROJECT=	torsocks
GH_TAGNAME=	96f7a0d

GNU_CONFIGURE=	yes
USES=		alias autoreconf gmake libtool
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	ChangeLog DEBUG SOCKS5 socks-extensions.txt
.endif

post-patch:
	${REINPLACE_CMD} -e 's,(defined(__linux__) || defined(__darwin__) || (defined(__FreeBSD_kernel__) && defined(__i386__))),defined(__FreeBSD__),' ${WRKSRC}/src/lib/syscall.c
	${REINPLACE_CMD} -e 's,(defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && defined(__x86_64),defined(badbadbad),' ${WRKSRC}/src/lib/syscall.c

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
