# New ports collection makefile for:	KCPUload
# Date Created:				10 Jan, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kcpuload
PORTVERSION=	1.99
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.brueffer.de/distfiles/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	CPU meter for Kicker

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
