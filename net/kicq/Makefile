# New ports collection makefile for:    kicq
# Version required:                     0.3.0
# Date created:                         16 March 1999
# Whom:                                 Pavel Andreev
#
# $FreeBSD$
#

DISTNAME=	kicq-0.3.0
CATEGORIES=	net kde
MASTER_SITES=	http://download.sourceforge.net/kicq/

MAINTAINER=	paxvel@iname.com

LIB_DEPENDS=	icq.1:${PORTSDIR}/net/icqlib \
		kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11 \
		kfm.3:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
