# New ports collection makefile for: neon
# Date created:		13 October 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	neon
PORTVERSION=	0.19.4
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/

MAINTAINER=	rooneg@electricjellyfish.net

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat

.ifndef WITHOUT_OPENSSL
USE_OPENSSL=	yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} \
		--enable-xml \
		--enable-shared \
		--with-expat=${PREFIX}
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=	neon-config.1
MAN3=	ne_close_connection.3 ne_session_create.3 \
	ne_session_decide_proxy.3 ne_session_destroy.3 ne_session_proxy.3

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${PREFIX}/man/man3
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/neon
	${INSTALL_DATA} ${WRKSRC}/doc/using-neon.txt ${PREFIX}/share/doc/neon
.endif

.include <bsd.port.mk>
