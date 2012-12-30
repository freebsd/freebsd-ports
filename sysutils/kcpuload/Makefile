# New ports collection makefile for:	KCPUload
# Date Created:				10 Jan, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kcpuload
PORTVERSION=	1.99
PORTREVISION=	13
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.brueffer.de/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CPU meter for Kicker

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
