# New ports collection makefile for:	akregator
# Date created:				2004-06-28
# Whom:					nsayer
#
# $FreeBSD$

PORTNAME=	akregator
PORTVERSION=	1.0.b8
PORTREVISION=	3
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/_beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RSS aggregator for KDE

BROKEN=		Does not compile

CONFLICTS=	kdepim-3.4.*

LIB_DEPENDS=	kdepim.1:${PORTSDIR}/deskutils/kdepim3

USE_BZIP2=		yes
USE_KDEBASE_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="${CFLAGS}"
USE_REINPLACE=		yes

.include <bsd.port.mk>
