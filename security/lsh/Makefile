# Created by: Eric Schwertfeger <eric@cybernut.com>
# $FreeBSD$

PORTNAME=	lsh
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Secure (encrypted) remote shell compatible with ssh 2

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liboop.so:${PORTSDIR}/devel/liboop \
		libgmp.so:${PORTSDIR}/math/gmp \
		libnettle.so:${PORTSDIR}/security/nettle

BROKEN_FreeBSD_9=	does not build
BROKEN_sparc64=	fails to compile: unexpected identifier

USE_CSTD=	c89
GNU_CONFIGURE=	yes
USE_XORG=	xau
USES=		cpe gmake shebangfix
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		lsh
CPE_VENDOR=	gnu

SHEBANG_FILES=	src/lcp

post-configure:
	${REINPLACE_CMD} 's,^#define WITH_READLINE,// &,' \
		${WRKSRC}/src/sftp/config.h

test:
	(cd ${WRKSRC}/src/testsuite && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
