# New ports collection makefile for:	hayes
# Date created:		Sun Jun 29 02:56:19 CEST 2003
# Whom:			Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		hayes
PORTVERSION=		1.4
PORTREVISION=	1
CATEGORIES=		multimedia kde
MASTER_SITES=		http://www.hakubi.us/hayes/

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		A filesystem-based playlist for Noatun

LIB_DEPENDS=		noatun:${PORTSDIR}/multimedia/kdemultimedia3

USE_KDEBASE_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=          yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
