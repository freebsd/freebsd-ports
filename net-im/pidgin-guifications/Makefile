# New ports collection makefile for:	gaim-guifications
# Date created:		2004-05-04
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	guifications
PORTVERSION=	1.8
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gaim-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Plugin to add msn style "toaster" popups to Gaim

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/gaim:configure
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	lthack gtk20
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--with-gaim=${WRKDIRPREFIX}${.CURDIR}/../../net/gaim/work/gaim*

.include <bsd.port.mk>
