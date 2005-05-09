# New ports collection makefile for:	gaim-bangexec
# Date created:		17 April 2005
# Whom:			kevinb
#
# $FreeBSD$
#

PORTNAME=	bangexec
PORTVERSION=	1.3.0.1
CATEGORIES=	misc
MASTER_SITES=	http://bard.sytes.net/bangexec/
PKGNAMEPREFIX=	gaim-

MAINTAINER=	kruptos@mlinux.org
COMMENT=	Command interpreter plugin for gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

PLIST_FILES=	lib/gaim/bangexec.so

post-patch:
	@${REINPLACE_CMD} -e 's|-g3||' ${WRKSRC}/configure

.include <bsd.port.mk>
