# Ports collection makefile for: aimage
# Date created: 	29/03/2008
# Whom: 		Chris Calvey <chris@securityforensics.co.uk>
#
# $FreeBSD$
#

PORTNAME=	aimage
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://afflib.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced Disk Imager

LIB_DEPENDS=	afflib:${PORTSDIR}/sysutils/afflib

USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:268

PLIST_FILES=	bin/aimage

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.68|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
