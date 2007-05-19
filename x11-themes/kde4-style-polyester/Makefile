# New ports collection makefile for:   polyester
# Date created:                        Sat May 20 00:41:23 CEST 2006
# Whom:                                Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	polyester
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.notmart.org/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	markus
PKGNAMEPREFIX=	kde-style-

MAINTAINER=	markus@FreeBSD.org
COMMENT=	KDE style and window decoration

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
