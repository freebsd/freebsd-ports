# New ports collection makefile for:  staticcharge
# Date created:        26 October 2001
# Whom:                Mahlon <mahlon@martini.nu>
#
# $FreeBSD$
#

PORTNAME=	staticcharge
PORTVERSION=	0.7
CATEGORIES=	net misc
MASTER_SITES=	http://www.staticcling.org/clients/
DISTNAME=	ChargeGTK-${PORTVERSION}

MAINTAINER=	mahlon@martini.nu

BUILD_DEPENDS=	lynx:${PORTSDIR}/www/lynx

WRKSRC=		${WRKDIR}/staticcharge
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
