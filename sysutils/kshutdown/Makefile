# New ports collection makefile for:	kshutdown
# Date created:				Mon Jan  9 18:06:42 CET 2006
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kshutdown
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KShutdown/${PORTVERSION}%20for%20KDE%203

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Advanced shutdown utility for KDE

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
