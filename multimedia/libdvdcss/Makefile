# ex:ts=8
# New ports collection makefile for:	libdvdcss
# Date created:		Jul 6, 2001
# Whom:			ijliao
#
# $FreeBSD$
#

PORTNAME=	libdvdcss
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Portable abstraction library for DVD decryption

NO_CDROM=	CSS code may violate the DMCA

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/ioctl.c

.include <bsd.port.mk>
