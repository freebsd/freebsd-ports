# New ports collection makefile for:	kmsn
# Date created:				Sunday June 10, 2001
# Whom:					Jonathan Belson (jon@witchspace.com)
#
# $FreeBSD$
#

PORTNAME=	kmsn
PORTVERSION=	0.2
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kmsn

MAINTAINER=	jon@witchspace.com

LIB_DEPENDS=	kmsn.1:${PORTSDIR}/net/libkmsn

USE_KDELIBS_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	${CONFIGURE_ENV}

.include <bsd.port.mk>
