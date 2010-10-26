# Ports collection makefile for: aimage
# Date created: 	29/03/2008
# Whom: 		Chris Calvey <chris@securityforensics.co.uk>
#
# $FreeBSD$
#

PORTNAME=	aimage
PORTVERSION=	3.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://afflib.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced Disk Imager

LIB_DEPENDS=	afflib:${PORTSDIR}/sysutils/afflib

USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/aimage

.include <bsd.port.mk>
