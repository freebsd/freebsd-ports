# Ports collection Makefile for:	bubblegum
# Date created:		5 November 2002
# Whom:			Ben Kibbey <bjk@arbornet.org>
#
# $FreeBSD$
#

PORTNAME=	bubblegum
PORTVERSION=	1.12
CATEGORIES=	security
MASTER_SITES=	http://arbornet.org/~bjk/bubblegum/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		bubblegum.1
MANCOMPRESSED=	no

pre-build:
	${CP} ${WRKSRC}/doc/bubblegum.man ${WRKSRC}/doc/bubblegum.1

.include <bsd.port.mk>
