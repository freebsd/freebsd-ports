# New ports collection makefile for:	akregator
# Date created:				2004-06-28
# Whom:					nsayer
#
# $FreeBSD$

PORTNAME=	akregator
PORTVERSION=	1.0.b4f
CATEGORIES=	www kde
#SF has some problem. This is a temporary mirror.
MASTER_SITES=	http://berk.upnet.ru/projects/kde/akregator/download/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	akregator-1.0_beta4fixed

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
