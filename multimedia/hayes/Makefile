# New ports collection makefile for:	hayes
# Date created:		Sun Jun 29 02:56:19 CEST 2003
# Whom:			Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		hayes
PORTVERSION=		1.4
PORTREVISION=	3
CATEGORIES=		multimedia kde
MASTER_SITES=		http://www.hakubi.us/hayes/

MAINTAINER=		markus@FreeBSD.org
COMMENT=		A filesystem-based playlist for Noatun

LIB_DEPENDS=		noatun:${PORTSDIR}/multimedia/kdemultimedia3

USE_KDEBASE_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes
CONFIGURE_ENV=		LDFLAGS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
