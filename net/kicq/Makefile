# New ports collection makefile for:    kicq
# Date created:                         16 March 1999
# Whom:                                 Pavel Andreev
#
# $FreeBSD$
#

PORTNAME=	kicq
PORTVERSION=	1.0.0
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	icq.1:${PORTSDIR}/net/icqlib

BROKEN=		Does not work with current icq protocol

USE_KDELIBS_VER=1
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
