# New ports collection makefile for:	hidentd
# Date created:				02.11.2003
# Whom:					Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hidentd
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	http://core.segfault.pl/~hobbit/hidentd/dist/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Simple and secure ident (RFC1413) server

USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN8=		hidentd.8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
