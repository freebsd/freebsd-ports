# New ports collection makefile for:	wmtop
# Date created:		07 May 2000
# Whom:			Dan Piponi <wmtop@tanelorn.demon.co.uk>
#
# $FreeBSD$

PORTNAME=	wmtop
PORTVERSION=	0.81
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wmtop@tanelorn.demon.co.uk

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
ALL_TARGET=	freebsd

MAN1=		wmtop.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/wmtop.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
