# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-stable/net-im/gaim-consoleui-devel/Makefile,v 1.2 2006/10/29 18:55:28 marcus Exp $

PORTNAME=	finch
PORTREVISION=	2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Finch multi-protocol messaging client (Console UI)

LIB_DEPENDS=	libpurple.so:net-im/libpurple

MASTERDIR=	${.CURDIR}/../libpurple
BUILD_WRKSRC=	${WRKSRC}/finch
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PIDGIN_SLAVE=	yes
WITH_CONSOLEUI=	yes

CPPFLAGS+=	-DNCURSES_WIDECHAR -D_XOPEN_SOURCE_EXTENDED
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtkui \
		--disable-nm \
		--with-dynamic_prpls=${PRPL_MODULES:S/,$//}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/finch.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
