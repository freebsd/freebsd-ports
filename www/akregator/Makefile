# New ports collection makefile for:	akregator
# Date created:				2004-06-28
# Whom:					nsayer
#
# $FreeBSD$

PORTNAME=	akregator
PORTVERSION=	1.0.b5
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/_beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RSS aggregator for KDE

LIB_DEPENDS=	kdepim.1:${PORTSDIR}/deskutils/kdepim3

USE_BZIP2=		yes
USE_KDEBASE_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="${CFLAGS}"
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
