# New ports collection makefile for:	apotheke
# Date created:		3 November 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	apotheke
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://ftp.berlios.de/pub/apotheke/

MAINTAINER=	martin.klaffenboeck@gmx.at

LIB_DEPENDS=	nautilus.2:${PORTSDIR}/x11-fm/nautilus2
RUN_DEPENDS=	ssh-askpass:${PORTSDIR}/security/openssh-askpass

USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
