# New ports collection makefile for:	platero
# Date created:			Sun Jun 15 23:24:46 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		platero
PORTVERSION=		1.0
CATEGORIES=		net kde
MASTER_SITES=		http://savannah.nongnu.org/download/platero/unstable.pkg/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=		${PORTNAME}-${PORTVERSION}-beta1

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		GUI to the P2P meta network client mldonkey for KDE

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
