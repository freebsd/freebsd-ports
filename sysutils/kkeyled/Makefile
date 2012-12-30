# New ports collection makefile for:	kkeyled
# Date created:			Tue Mar  2 05:10:59 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kkeyled
PORTVERSION=	0.8.11
PORTREVISION=	6
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Panel applet to display the keyboard's LED states

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
