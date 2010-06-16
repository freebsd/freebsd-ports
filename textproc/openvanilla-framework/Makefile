# New ports collection makefile for:	openvanilla-framework
# Date Created:				3 September 2005
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	openvanilla-framework
PORTVERSION=	0.7.2.20070514
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rafan
DISTNAME=	openvanilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Development header files for OpenVanilla

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/include/OpenVanilla
	@${INSTALL_DATA} ${WRKSRC}/Framework/Headers/* ${PREFIX}/include/OpenVanilla

.include <bsd.port.mk>
