# New ports collection makefile for:	Quanta+
# Date created:				19 May 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quanta
PORTVERSION= 	1.0.2
CATEGORIES=	www kde
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/quanta/ \
		http://download.sourceforge.net/quanta/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdeui.3:${PORTSDIR}/x11/kdelibs11/

USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

.include <bsd.port.mk>
