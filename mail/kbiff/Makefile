# New ports collection makefile for:	kbiff
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	kbiff
PORTVERSION=	3.9
PORTREVISION=	4
CATEGORIES=	mail kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail notification utility for KDE with nice features

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--disable-fast-perl

MAN1=		kbiff.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS}|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g ; \
		 /if test/s|==|=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
