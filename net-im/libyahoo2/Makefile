# ex:ts=8
# Ports collection makefile for:	libyahoo2
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libyahoo2
PORTVERSION=	0.7.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library that handles the new Yahoo! Messenger protocol

USE_BZIP2=	yes
USE_GNOME=	glib20 gnomehack gnometarget
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -ansi -pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-g -Wall||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
