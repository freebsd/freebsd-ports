# New ports collection makefile for: dotfile
# Version required:  2.0b2
# Date created:      11/12/96
# Whom:              oly@world.std.com
#
# $Id: Makefile,v 1.2 1997/01/06 02:49:36 obrien Exp $
#

DISTNAME=	dotfile-2.0b5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
MAN1=		dotfile.1

do-build:
	@${DO_NADA}

post-install:
	@${CAT} ${PKGDIR}/MESSAGE
	
.include <bsd.port.mk>
