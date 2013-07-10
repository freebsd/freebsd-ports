# Created by: Matthew Holder <sixxgate@hotmail.com>
# $FreeBSD$

PORTNAME=	graphicboot
PORTVERSION=	1.1
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://matt.sixxgate.com/files/

MAINTAINER=	sixxgate@hotmail.com
COMMENT=	Provides graphical X Window startup to FreeBSD during 'rc'

BUILD_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage \
		xrdb:${PORTSDIR}/x11/xrdb \
		xsetroot:${PORTSDIR}/x11/xsetroot
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		motif gmake
USE_BZIP2=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes

MAN8=		graphicboot.8 sendgbmsg.8
MANCOMPRESSED=	yes

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
