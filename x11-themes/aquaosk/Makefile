# New ports collection makefile for:	aquaosk
# Date created:		Wed Apr 14 08:28:56 EDT 2003
# Whom:			Brian Skrab <brian@quynh-and-brian.org>
#
# $FreeBSD$
#

PORTNAME=	aquaosk
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.davidsansome.com/ \
		http://cottage.quynh-and-brian.org/freebsd/ports/distfiles/

MAINTAINER=	brian@quynh-and-brian.org
COMMENT=	An Acqua-like native window decoration for KDE 3

BROKEN=		Does not build since KDE 3.2

CONFIGURE_ARGS=	--prefix=${PREFIX}
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
USE_KDEBASE_VER=3
USE_BZIP2=	yes

.include <bsd.port.mk>
