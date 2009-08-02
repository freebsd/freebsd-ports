# New ports collection makefile for:	dolphin
# Date created:				Tue Feb 27 05:11:09 CET 2007
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dolphin
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	x11-fm kde
MASTER_SITES=	http://www.brueffer.de/distfiles/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	File manager for KDE

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

post-patch:
	@${TOUCH} ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
