# New ports collection makefile for:	katalog
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	katalog
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	misc kde
MASTER_SITES=	http://salvaste.altervista.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD organizer for KDE

USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
