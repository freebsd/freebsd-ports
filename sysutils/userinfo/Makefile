# Ports collection Makefile for:	userinfo
# Date created:		5 November 2002
# Whom:			Ben Kibbey <bjk@arbornet.org>
#
# $FreeBSD$
#

PORTNAME=	userinfo
PORTVERSION=	2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://arbornet.org/~bjk/userinfo/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	bjk@m-net.arbornet.org
COMMENT=	Show information about local users

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		ui.1

pre-build:
	${MV} ${WRKSRC}/doc/ui.1 ${WRKSRC}/doc/ui.1

.include <bsd.port.mk>
