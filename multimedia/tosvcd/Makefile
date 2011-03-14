# ex:ts=8
# Ports collection makefile for:	tosvcd
# Date created:			Oct 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tosvcd
PORTVERSION=	0.9
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	http://linvdr.org/download/tosvcd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SVCD transcoder

DEPRECATED=     Upstream has disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ONLY_FOR_ARCHS=	i386

RUN_DEPENDS=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		vcdimager:${PORTSDIR}/multimedia/vcdimager

PLIST_FILES=	bin/tosvcd
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
