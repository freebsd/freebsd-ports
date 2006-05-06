# New ports collection makefile for:	gaim-bangexec
# Date created:		17 April 2005
# Whom:			kevinb
#
# $FreeBSD$
#

PORTNAME=	bangexec
PORTVERSION=	1.3.0.2
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://thefnords.googlepages.com/
PKGNAMEPREFIX=	gaim-

MAINTAINER=	kruptos@mlinux.org
COMMENT=	Command interpreter plugin for gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

DEPRECATED=	The author has taken down his site and has ceased developing this program

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/gaim/bangexec.la lib/gaim/bangexec.so

post-patch:
	@${REINPLACE_CMD} -e 's|-g3||' ${WRKSRC}/configure

.include <bsd.port.mk>
