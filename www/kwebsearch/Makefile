# New ports collection makefile for:	kwebsearch
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kwebsearch
PORTVERSION= 	1.2
CATEGORIES=	www kde
MASTER_SITES=	http://www.bawue.de/~rgoetz/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
BUILD_DEPENDS=	${LOCALBASE}/bin/gettext:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_GMAKE=      yes
USE_QT=		yes

.include <bsd.port.mk>
