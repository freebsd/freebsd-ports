# New ports collection makefile for:	bookcase
# Date created:				11 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	tellico
PORTVERSION=	0.13.7
CATEGORIES=	misc kde
MASTER_SITES=	http://www.periapsis.org/tellico/download/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Collection manager for KDE

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib \
		kcddb:${PORTSDIR}/multimedia/kdemultimedia3 \
		yaz.2:${PORTSDIR}/net/yaz

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
