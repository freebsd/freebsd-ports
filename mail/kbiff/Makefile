# New ports collection makefile for:	kbiff
# Version required:	0.7.3
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $Id: Makefile,v 1.6 1998/04/29 17:53:11 asami Exp $
#

DISTNAME=	kbiff-0.7.3
CATEGORIES=	mail kde
MASTER_SITES=	http://www.geocities.com/SiliconValley/Hills/2651/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt \
		kdeui\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs \
		kdecore\\.0\\.9[0-9]:${PORTSDIR}/x11/kdelibs

FETCH_BEFORE_ARGS=-t
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
