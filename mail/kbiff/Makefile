# New ports collection makefile for:	kbiff
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	kbiff
PORTVERSION=	3.7.1
PORTREVISION=	2
CATEGORIES=	mail kde
MASTER_SITES=	http://devel-home.kde.org/~granroth/kbiff/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail notification utility for KDE with nice features

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-fast-perl

MAN1=		kbiff.1

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
