# New ports collection makefile for:	stone
# Date created:		25 April 2001
# Whom:			Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	stone
PORTVERSION=	2.3e
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.gcd.org/sengoku/stone/

MAINTAINER=	sarumaru@jp.FreeBSD.org
COMMENT=	Stone is a TCP/IP packet repeater in the application layer

WRKSRC=		${WRKDIR}/${PORTNAME}-2.3d-2.3.2.7

MAN1=		stone.1
MANLANG=	"" ja

USE_RC_SUBR=	stone
USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SSL)
.undef USE_OPENSSL
ALL_TARGET=	bsd-pop
MAKE_ARGS=	POP_LIBS="-lmd" LIBS="-DUNIX_DAEMON"
post-extract:
	${TOUCH} ${WRKSRC}/global.h
.else
ALL_TARGET=	bsd-ssl
MAKE_ARGS=	SSL_FLAGS="-DUSE_SSL -I${OPENSSLINC}" \
		SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" LIBS="-DUNIX_DAEMON"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stone ${PREFIX}/bin/stone
	${INSTALL_MAN} ${FILESDIR}/stone.1 ${PREFIX}/man/man1/stone.1
	${INSTALL_MAN} ${FILESDIR}/stone.1.ja ${PREFIX}/man/ja/man1/stone.1
	${INSTALL_DATA} ${FILESDIR}/stone.cnf ${PREFIX}/etc/stone.cnf.sample
.if !exists(${PREFIX}/etc/stone.cnf)
	${INSTALL_DATA} ${FILESDIR}/stone.cnf ${PREFIX}/etc
.endif

.include <bsd.port.post.mk>
