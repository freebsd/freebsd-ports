# New ports collection makefile for: apollon
# Date Created:			29 Dec 2004
# Whom:				Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	apollon
PORTVERSION=	1.0.2.1
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE client for giFT daemon

LIB_DEPENDS=	gift.0:${PORTSDIR}/net-p2p/gift

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

.include <bsd.port.mk>
