# New ports collection makefile for:	stone
# Date created:		25 April 2001
# Whom:			Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	stone
PORTVERSION=	2.2b
CATEGORIES=	net
MASTER_SITES=	http://www.gcd.org/sengoku/stone/

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	Stone is a TCP/IP packet repeater in the application layer

MAN1=		${PORTNAME}.1
MANLANG=	"" ja
PLIST_FILES=	bin/stone

USE_REINPLACE=   yes

.if exists(${PREFIX}/lib/libssl.so)
ALL_TARGET=	bsd-ssl
MAKE_ARGS=	-e SSL_FLAGS="-DUSE_SSL -I${PREFIX}/include" SSL_LIBS="-L${PREFIX}/lib -lssl -lcrypto"
.elif exists(/usr/lib/libssl.so)
ALL_TARGET=	bsd-ssl
MAKE_ARGS=	-e SSL_FLAGS="-DUSE_SSL" SSL_LIBS="-lssl -lcrypto"
.else
ALL_TARGET=	bsd-pop
MAKE_ARGS=	-e POP_LIBS="-lmd"
NEED_GLOBAL_H=	yes
.endif

pre-everything::
.if ${ALL_TARGET} != bsd-ssl
	@${ECHO_CMD} "You can build stone with SSL support by installing OpenSSL."
.endif

pre-patch:
	${REINPLACE_CMD} -e "s/-D_THREAD_SAFE/${PTHREAD_CFLAGS}/g;s/-pthread/${PTHREAD_LIBS}/g" ${WRKSRC}/Makefile

pre-build:
.if defined(NEED_GLOBAL_H)
	${TOUCH} ${WRKSRC}/global.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stone ${PREFIX}/bin/stone
	${INSTALL_MAN} ${WRKSRC}/stone.1 ${PREFIX}/man/man1/stone.1
	${INSTALL_MAN} ${WRKSRC}/stone.1.ja ${PREFIX}/man/ja/man1/stone.1

#.include <bsd.port.post.mk>
.include <bsd.port.mk>
