# ex:ts=8
# New ports collection makefile for:	libdvdcss
# Date created:		Jul 6, 2001
# Whom:			ijliao
#
# $FreeBSD$
#

PORTNAME=	libdvdcss
PORTVERSION=	1.2.4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/videolan/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/ioctl.c

.include <bsd.port.mk>
