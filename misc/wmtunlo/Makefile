# New ports collection makefile for:	wmtunlo
# Date created:			27 July 2002
# Whom:				Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	wmtunlo
PORTVERSION=	0.1.3
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://clay.ll.pl/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A falling-down-a-tunnel dockapp

USE_X_PREFIX=	yes
ALL_TARGET=	wmtunlo

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmtunlo ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/* \
		${EXAMPLESDIR}

.include <bsd.port.mk>
