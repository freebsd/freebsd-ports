# New ports collection makefile for:	kgpg
# Date created:				15 Nov 2002
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=		kgpg
PORTVERSION=		1.0.0
PORTREVISION=	4
CATEGORIES=		security kde
MASTER_SITES=		http://developer.kde.org/~kgpg/src/

MAINTAINER=		rick@rptn.net
COMMENT=		A simple KDE frontend for GnuPG

RUN_DEPENDS=		gpg:${PORTSDIR}/security/gnupg

CONFLICTS=		kdeutils-3.[2-4].*

USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
USE_KDELIBS_VER=	3

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
