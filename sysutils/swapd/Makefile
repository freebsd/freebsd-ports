# New ports collection makefile for:	swapd
# Date created:				August 16, 2007
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	swapd
PORTVERSION=	1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rkeene.org/files/oss/swapd/source/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A daemon that watches free memory and manages swap files

LIB_DEPENDS=	statgrab:${PORTSDIR}/devel/libstatgrab

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_RC_SUBR=	swapd
MAN5=		swapd.conf.5
MAN8=		swapd.8

.include <bsd.port.mk>
