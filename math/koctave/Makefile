# New ports collection makefile for:	koctave
# Date created:				01 August 2003
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	koctave3
PORTVERSION=	0.65
PORTREVISION=	3
CATEGORIES=	math kde
MASTER_SITES=	http://lehmann.in-berlin.de/bsd/

MAINTAINER=	kay_lehmann@web.de
COMMENT=	KDEGUI for octave

RUN_DEPENDS=	octave:${PORTSDIR}/math/octave

USE_BZIP2=	yes
USE_INC_LIBTOOL_VER=13
USE_QT_VER=	3
USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--program-transform-name=koctave3

.include <bsd.port.mk>
