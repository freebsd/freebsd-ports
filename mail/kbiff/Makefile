# New ports collection makefile for:	kbiff
# Version required:	2.3
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $Id: Makefile,v 1.9 1999/03/19 04:39:56 nectar Exp $
#

DISTNAME=	kbiff-2.3
CATEGORIES=	mail kde
MASTER_SITES=	http://home.sprintmail.com/~granroth/kbiff/

MAINTAINER=	kris@FreeBSD.ORG

LIB_DEPENDS=	kdeui.2:${PORTSDIR}/x11/kdelibs11 \
		intl.1:${PORTSDIR}/devel/gettext

USE_QT=		yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

.include <bsd.port.mk>
