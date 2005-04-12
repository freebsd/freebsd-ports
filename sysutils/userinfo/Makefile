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
COMMENT=	Show information about local users

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		ui.1
PLIST_FILES=	bin/ui

pre-build:
	${MV} ${WRKSRC}/doc/ui.man ${WRKSRC}/doc/ui.1

.include <bsd.port.mk>
