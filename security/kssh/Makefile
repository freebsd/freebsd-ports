# New ports collection makefile for:	kssh
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kssh
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.geocities.com/bilibao/

MAINTAINER=	kevlo@FreeBSD.org

BROKEN=		"Does not build"

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-0.4

.include <bsd.port.mk>
