# New ports collection makefile for:	platero
# Date created:			Sun Jun 15 23:24:46 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		platero
PORTVERSION=		1.0
CATEGORIES=		net kde
MASTER_SITES=		http://www.unixpages.org/distfiles/
DISTNAME=		${PORTNAME}-${PORTVERSION}-beta1

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		GUI to the P2P meta network client mldonkey for KDE

USE_KDEBASE_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
