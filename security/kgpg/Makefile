# New ports collection makefile for:	kgpg
# Date created:				15 Nov 2002
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=		kgpg
PORTVERSION=		1.0.0
PORTREVISION=	1
CATEGORIES=		security kde
MASTER_SITES=		http://devel-home.kde.org/~kgpg/src/

MAINTAINER=		rick@rptn.net
COMMENT=		A simple KDE frontend for GnuPG

RUN_DEPENDS=		gpg:${PORTSDIR}/security/gnupg

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_KDELIBS_VER=	3
_NO_KDE_FIXPTHREAD=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
