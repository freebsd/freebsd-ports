#
# New ports collection makefile for:	tolua
# Date created:				21 November 2004
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	tolua4
PORTVERSION=	4.0a
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/users/celes/tolua/ \
		http://www.tecgraf.puc-rio.br/~celes/tolua/
DISTNAME=	tolua-4.0a

MAINTAINER=	edwin@mavetju.org
COMMENT=	toLua: accessing C/C++ code from Lua

LIB_DEPENDS=	lua.4:${PORTSDIR}/lang/lua4

WRKSRC=		${WRKDIR}/tolua
USE_GMAKE=	yes
CONFLICTS=	tolua-5.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tolua ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/tolua.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua.a ${PREFIX}/lib

.include <bsd.port.mk>
