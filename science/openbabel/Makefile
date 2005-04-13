# ex:ts=8
# Ports collection makefile for:	openbabel
# Date created:			Jan 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openbabel
PORTVERSION=	1.100.2
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chemistry file translation program

USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=open
INSTALLS_SHLIB=	yes

MAN1=	openbabel.1

.include <bsd.port.mk>
