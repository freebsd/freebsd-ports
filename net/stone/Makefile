# Created by: Yoshihiko Sarumaru <mistral@imasy.or.jp>
# $FreeBSD$

PORTNAME=	stone
PORTVERSION=	2.3e
CATEGORIES=	net
MASTER_SITES=	http://www.gcd.org/sengoku/stone/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stone is a TCP/IP packet repeater in the application layer

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-2.3d-2.3.2.7

USE_RC_SUBR=	stone
.if !defined(WITHOUT_SSL)
USES=		ssl
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SSL)
ALL_TARGET=	bsd-pop
MAKE_ARGS=	POP_LIBS="-lmd" LIBS="-DUNIX_DAEMON"
post-extract:
	${TOUCH} ${WRKSRC}/global.h
.else
ALL_TARGET=	bsd-ssl
MAKE_ARGS=	SSL_FLAGS="-DUSE_SSL -I${OPENSSLINC}" \
		SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" LIBS="-DUNIX_DAEMON"
.endif

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct ssl_session_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct ssl_session_st'
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stone ${STAGEDIR}${PREFIX}/bin/stone
	${INSTALL_MAN} ${FILESDIR}/stone.1 ${STAGEDIR}${PREFIX}/man/man1/stone.1
	${INSTALL_MAN} ${FILESDIR}/stone.1.ja ${STAGEDIR}${PREFIX}/man/ja/man1/stone.1
	${INSTALL_DATA} ${FILESDIR}/stone.cnf ${STAGEDIR}${PREFIX}/etc/stone.cnf.sample

.include <bsd.port.post.mk>
