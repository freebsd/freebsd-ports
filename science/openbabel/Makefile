# ex:ts=8
# Ports collection makefile for:	openbabel
# Date created:			Jan 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openbabel
PORTVERSION=	1.100.1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chemistry file translation program

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static --program-prefix=open
USE_GNOME=	gnomehack gnometarget

MAN1=	openbabel.1

post-install:
	${MKDIR} ${PREFIX}/include/openbabel/math
	${INSTALL_DATA} ${WRKSRC}/src/math/*.h ${PREFIX}/include/openbabel/math

.include <bsd.port.mk>
