# Ports collection Makefile for:	userinfo
# Date created:		5 November 2002
# Whom:			Ben Kibbey <bjk@arbornet.org>
#
# $FreeBSD$
#

PORTNAME=	userinfo
PORTVERSION=	1.10a
CATEGORIES=	sysutils
MASTER_SITES=	http://arbornet.org/~bjk/userinfo/

MAINTAINER=	bjk@m-net.arbornet.org

GNU_CONFIGURE=	yes

MAN1=		ui.1
MANCOMPRESSED=	no

CONFIGURE_TARGET=

pre-build:
	${CP} ${WRKSRC}/doc/ui.man ${WRKSRC}/doc/ui.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
IGNORE=	"Doesn't work on 5.x"
.endif

.include <bsd.port.post.mk>
