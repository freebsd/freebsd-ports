# New ports collection makefile for:	kbiff
# Version required:	0.7.3
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $Id: Makefile,v 1.1.1.1 1998/06/14 17:32:11 andreas Exp $
#

DISTNAME=	kbiff-0.7.3
CATEGORIES=	mail kde
MASTER_SITES=	http://www.geocities.com/SiliconValley/Hills/2651/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11-toolkits/qt \
		kdeui\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs

FETCH_BEFORE_ARGS=-t
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
