# New ports collection makefile for:   wmx10
# Date created:                                16 September 2000
# Whom:                                        eric
#
# $FreeBSD$
#

PORTNAME=	wmx10
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://www.cs.uml.edu/~jhawkins/wmx10/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remote control for X10 devices

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

PLIST_FILES=	bin/wmx10
WRKSRC=		${WRKDIR}/wmx10.app/wmx10

USE_GMAKE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
