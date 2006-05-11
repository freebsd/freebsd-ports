# New ports collection makefile for:	gaim-slashexec
# Date created:		30 December 2005
# Whom:			kevinb
#
# $FreeBSD$
#

PORTNAME=	slashexec
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	guifications
PKGNAMEPREFIX=	gaim-

MAINTAINER=	kruptos@mlinux.org
COMMENT=	Execute commands inside gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/gaim/se.la lib/gaim/se.so

.include <bsd.port.mk>
