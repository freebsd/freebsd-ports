# New ports collection makefile for:	trix
# Date created:				17 April 2008
# Whom:			Kozienko Aleksandr <pascalamsg@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	trix
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	pascalamsg@gmail.com
COMMENT=	TriX is a chat compatible with 2.0 protocol of the Vypress Chat

USE_QT_VER=	3
USE_GMAKE=	yes
USE_PERL5=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS +=	--with-qt-dir=${QT_PREFIX} \
			--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib

.if !defined(WITHOUT_PLAY)
BUILD_DEPENDS=	play:${PORTSDIR}/audio/play
.endif

post-extract:
	    ${CHMOD} 744 ${WRKSRC}/install-sh

.include <bsd.port.mk>
