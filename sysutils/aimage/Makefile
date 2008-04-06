# Ports collection makefile for: aimage
# Date created: 	29/03/2008
# Whom: 		Chris Calvey <chris@securityforensics.co.uk>
#
# $FreeBSD$
#

PORTNAME=	aimage
PORTVERSION=	3.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.afflib.org/downloads/

MAINTAINER=	chris@securityforensics.co.uk
COMMENT=	Advanced Disk Imager

LIB_DEPENDS=	afflib:${PORTSDIR}/sysutils/afflib

USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:261

PLIST_FILES=	bin/aimage

.include <bsd.port.mk>
