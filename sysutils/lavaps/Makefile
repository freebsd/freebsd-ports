# Generated automatically from Makefile.in by configure.
# New ports collection makefile for:    lavaps
# Version required:     1.8
# Date created:         11-Oct-99
# Whom:                 johnh@isi.edu
#
# $Id: Makefile,v 1.4 1997/05/06 22:47:03 johnh Exp johnh $
# $FreeBSD$
#

DISTNAME=       lavaps-1.8
CATEGORIES=     sysutils
MASTER_SITES=   http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=     johnh@isi.edu

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

GNU_CONFIGURE=  yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
USE_NEWGCC=	yes
MAN1=           lavaps.1

.include <bsd.port.mk>
