# New ports collection makefile for:	vic
# Version required:	2.6
# Date created:		14 December 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.1.1.1 1994/10/13 00:50:38 wollman Exp $
#

DISTNAME=	vic-2.6
DISTFILES=	vicsrc-2.6.tar.Z
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DEPENDS=	${PORTSDIR}/x11/blt
HAS_CONFIGURE=	yes
INSTALL_TARGET=	MANDIR=${PREFIX}/man/manl install

pre-install:
	mkdir -p ${PREFIX}/man/manl

.include <bsd.port.mk>

