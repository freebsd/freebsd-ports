# New ports collection makefile for:	openvanilla-framework
# Date Created:				3 September 2005
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	openvanilla-framework
PORTVERSION=	0.7.2.b20060214
CATEGORIES=	textproc
MASTER_SITES=	http://www.csie.org/~llwang/	\
		http://www.infor.org/~llwang/
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	Development header files for OpenVanilla

USE_X_PREFIX=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/include/OpenVanilla
	@${INSTALL_DATA} ${WRKSRC}/Framework/Headers/* ${PREFIX}/include/OpenVanilla

.include <bsd.port.mk>
