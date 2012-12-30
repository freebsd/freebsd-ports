# New ports collection makefile for:	ksynaptics
# Date created:				Sun Mar 19 23:11:08 CET 2006
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ksynaptics
PORTVERSION=	0.3.1
PORTREVISION=	6
CATEGORIES=	sysutils kde
MASTER_SITES=	http://qsynaptics.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE control center module for Synaptics touchpads

LIB_DEPENDS=	synaptics:${PORTSDIR}/x11/libsynaptics

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|/usr/include/synaptics|${LOCALBASE}/include/synaptics|g' \
		${WRKSRC}/ksynaptics/src/Makefile.in

.include <bsd.port.mk>
