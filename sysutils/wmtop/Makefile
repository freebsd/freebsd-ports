# New ports collection makefile for:	wmtop
# Date created:		07 May 2000
# Whom:			Dan Piponi <wmtop@tanelorn.demon.co.uk>
#
# $FreeBSD$

PORTNAME=	wmtop
PORTVERSION=	0.83
CATEGORIES=	sysutils
MASTER_SITES=	http://wmtop.sourceforge.net/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wmtop@tanelorn.demon.co.uk

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	freebsd

MAN1=		wmtop.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/wmtop.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
