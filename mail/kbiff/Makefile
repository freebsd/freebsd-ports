# New ports collection makefile for:	kbiff
# Version required:	0.7.3
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $Id: Makefile,v 1.7 1998/10/02 08:16:56 brian Exp $
#

DISTNAME=	kbiff-2.0
CATEGORIES=	mail kde
MASTER_SITES=	http://home.sprintmail.com/~granroth/kbiff/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	kdeui.1:${PORTSDIR}/x11/kdelibs \
		kdecore.1:${PORTSDIR}/x11/kdelibs

USE_QT=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

.include <bsd.port.mk>
