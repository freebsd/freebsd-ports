#
# New ports collection makefile for:	tolua
# Date created:				21 November 2004
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	tolua
PORTVERSION=	5.0.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/users/celes/tolua/ \
		http://www.tecgraf.puc-rio.br/~celes/tolua/

MAINTAINER=	edwin@mavetju.org
COMMENT=	toLua: accessing C/C++ code from Lua

LIB_DEPENDS=	lua:${PORTSDIR}/lang/lua

WRKSRC=		${WRKDIR}/${PORTNAME}-5.0
USE_GMAKE=	yes
CONFLICTS=	tolua4-.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tolua ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/tolua.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua.a ${PREFIX}/lib

.include <bsd.port.mk>
