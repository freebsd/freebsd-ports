# New ports collection makefile for:	libsupertone
# Date created:				26 Jun 2012
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsupertone
PORTVERSION=	0.0.2
CATEGORIES=	misc
MASTER_SITES=	http://www.soft-switch.org/downloads/unicall/
EXTRACT_SUFX=	.tgz

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A library for supervisory tone generation and detection

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile\
		spandsp.2:${PORTSDIR}/comms/spandsp-devel\
		tiff.4:${PORTSDIR}/graphics/tiff\
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
LICENSE=	LGPL21

.include <bsd.port.mk>
