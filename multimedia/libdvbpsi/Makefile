# New ports collection makefile for:	libdvbpsi
# Date created:		Sat Feb 8 01:16:45 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdvbpsi
PORTVERSION=	0.1.2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
