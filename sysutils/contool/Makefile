# New ports collection makefile for:    contool
# Date created:         2 Dec 1996
# Whom:                 nsayer@quack.kfu.com
#
# $FreeBSD$
#

PORTNAME=	contool
PORTVERSION=	3.3a
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nsayer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console tool for openlook

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

NO_CDROM=	"source code cannot be sold, nor can you incorporate the source code into a product which is subsequently sold"
NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

MAN1=		contool.1

pre-install:
	@${MKDIR} ${PREFIX}/lib/help

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
