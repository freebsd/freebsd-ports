# New ports collection makefile for:	asapm
# Version required:	2.3
# Date created:		6 Aug 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.5 1998/11/29 12:43:12 asami Exp $
#

DISTNAME=	asapm-2.3
CATEGORIES=	sysutils
MASTER_SITES=	http://bewoner.dma.be/Albert/linux/software/

MAINTAINER=	handy@physics.montana.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install.man

MAN1=		asapm.1

FETCH_BEFORE_ARGS=	-b

.include <bsd.port.mk>
