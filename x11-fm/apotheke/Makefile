# New ports collection makefile for:	apotheke
# Date created:		3 November 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	apotheke
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://ftp.berlios.de/pub/apotheke/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CVS view for Nautilus

RUN_DEPENDS=	ssh-askpass:${PORTSDIR}/security/openssh-askpass

USE_GNOME=	gnomehack gnomeprefix nautilus2
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
