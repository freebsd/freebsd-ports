# New ports collection makefile for:	kbiff
# Version required:	0.7.3
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $Id: Makefile,v 1.8 1998/12/28 23:44:04 dirk Exp $
#

DISTNAME=	kbiff-2.0
CATEGORIES=	mail kde
MASTER_SITES=	http://home.sprintmail.com/~granroth/kbiff/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=	kdeui.1:${PORTSDIR}/x11/kdelibs \
		intl.1:${PORTSDIR}/devel/gettext

USE_QT=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

.include <bsd.port.mk>
