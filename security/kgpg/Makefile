# New ports collection makefile for:	kgpg
# Date created:				15 Nov 2002
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=		kgpg
PORTVERSION=		0.9.2
CATEGORIES=		security kde
MASTER_SITES=		http://devel-home.kde.org/~kgpg/src/

MAINTAINER=		rick@help-desk.ca

RUN_DEPENDS=		gpg:${PORTSDIR}/security/gnupg

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_KDELIBS_VER=	3

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
