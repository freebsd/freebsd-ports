# Generated automatically from Makefile.in by configure.
# New ports collection makefile for:    lavaps
# Version required:     1.8
# Date created:         11-Oct-99
# Whom:                 johnh@isi.edu
#
# $FreeBSD$
#

DISTNAME=       lavaps-1.8
CATEGORIES=     sysutils
MASTER_SITES=   http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=     johnh@isi.edu

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=  yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-tcl-ver=8.2 --with-tk-ver=8.2
USE_NEWGCC=	yes
MAN1=           lavaps.1

.include <bsd.port.mk>
