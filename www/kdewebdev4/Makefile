# New ports collection makefile for:	Quanta+
# Date created:				19 May 2000
# Whom:					Will Andrews <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quanta
PORTVERSION= 	1.0.2
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	kdeui.3:${PORTSDIR}/x11/kdelibs11/
BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext/

USE_BZIP2=	yes
USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

.include <bsd.port.mk>
