# New ports collection makefile for:	asapm
# Version required:	2.7
# Date created:		6 Aug 1998
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.9 1999/04/08 11:11:43 jseger Exp $
#

DISTNAME=	asapm-2.7
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.afterstep.org/apps/asapm/ \
		http://www.tigr.net/afterstep/as-apps/download/asapm/

MAINTAINER=	handy@physics.montana.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

ONLY_FOR_ARCHS=	i386

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install.man

MAN1=		asapm.1

FETCH_BEFORE_ARGS=	-b

.include <bsd.port.mk>
