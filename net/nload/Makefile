# New ports collection makefile for: nload
# Date created:		24 April 2002
# Whom:			Olivier Tharan <olive@oban.frmug.org>
#
# $FreeBSD$
#

PORTNAME=	nload
PORTVERSION=	0.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	olive@oban.frmug.org

HAS_CONFIGURE=	yes

MAN1=		nload.1
MANCOMPRESSED=	yes

post-install:
	strip ${PREFIX}/bin/nload

.include <bsd.port.mk>
