# New ports collection makefile for:	akregator
# Date created:				2004-06-28
# Whom:					nsayer
#
# $FreeBSD$

PORTNAME=	akregator
PORTVERSION=	1.0.b3
CATEGORIES=	www kde
MASTER_SITES=	http://akregator.upnet.ru/
DISTNAME=	akregator-1.0_beta3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An RSS aggregator for KDE

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="${CFLAGS}"
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
