# New ports collection makefile for:	krusader
# Date created:		21-04-2003
# Whom:			Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	krusader
PORTVERSION=	1.20
CATEGORIES=	x11-fm kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=krusader

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A two window file-manager for KDE, like midnight or norton commander

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
