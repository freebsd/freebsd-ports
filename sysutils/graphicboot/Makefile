# New ports collection makefile for:	graphicboot
# Date created:		8 July 2005
# Whom:			Matthew Holder <sixxgate@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	graphicboot
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://matt.sixxgate.com/files/

MAINTAINER=	sixxgate@hotmail.com
COMMENT=	Provides graphical X Window startup to FreeBSD during 'rc'

BUILD_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage \
		xrdb:${PORTSDIR}/x11/xrdb \
		xsetroot:${PORTSDIR}/x11/xsetroot
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_MOTIF=	yes
USE_BZIP2=	yes
USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN8=		graphicboot.8 sendgbmsg.8
MANCOMPRESSED=	yes

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
