# New ports collection makefile for:	katalog
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	katalog
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	http://salvaste.altervista.org/

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	CD organizer for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
