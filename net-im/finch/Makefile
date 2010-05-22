# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/net-im/gaim-consoleui-devel/Makefile,v 1.2 2006/10/29 18:55:28 marcus Exp $
#

PORTNAME=	finch
PORTREVISION=	0

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Finch multi-protocol messaging client (Console UI)

LIB_DEPENDS=	purple.7:${PORTSDIR}/net-im/libpurple

MASTERDIR=	${.CURDIR}/../libpurple
BUILD_WRKSRC=	${WRKSRC}/finch
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PIDGIN_SLAVE=	yes
WITH_CONSOLEUI=	yes

USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtkui \
		--disable-nm \
		--with-dynamic_prpls=${PRPL_MODULES:S/,$//}

MAN1=		finch.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/finch.1 ${MAN1PREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
