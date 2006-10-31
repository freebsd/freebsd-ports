# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/net-im/gaim-consoleui-devel/Makefile,v 1.2 2006/10/29 18:55:28 marcus Exp $
#

PORTNAME=	gaim
PKGNAMEPREFIX=
PKGNAMESUFFIX=	-consoleui-devel

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Gaim multi-protocol messaging client (Console UI)

LIB_DEPENDS=	gaim.0:${PORTSDIR}/net-im/libgaim

MASTERDIR=	${.CURDIR}/../libgaim
BUILD_WRKSRC=	${WRKSRC}/console
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

GAIM_SLAVE=	yes
WITH_CONSOLEUI=	yes

USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtkui

.include "${MASTERDIR}/Makefile"
