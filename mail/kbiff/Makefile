# New ports collection makefile for:	kbiff
# Version required:	0.7.3
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $Id: Makefile,v 1.5 1998/08/31 21:13:57 andreas Exp $
#

DISTNAME=	kbiff-0.8
CATEGORIES=	mail kde
MASTER_SITES=	http://www.geocities.com/SiliconValley/Hills/2651/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=	kdeui\\.1\\.:${PORTSDIR}/x11/kdelibs \
		kdecore\\.1\\.:${PORTSDIR}/x11/kdelibs

BROKEN_ELF=	depends on kdelibs

USE_QT=		yes
FETCH_BEFORE_ARGS=-t
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
