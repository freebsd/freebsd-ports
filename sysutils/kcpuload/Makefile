# New ports collection makefile for:	KCPUload
# Date Created:				10 Jan, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kcpuload
PORTVERSION=	1.99
PORTREVISION=	5
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.brueffer.de/distfiles/

MAINTAINER=	ports@freebsd.org
COMMENT=	CPU meter for Kicker

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
