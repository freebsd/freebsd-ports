# New ports collection makefile for:	grpn
# Date created:				25 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grpn
PORTVERSION=	1.1.1
CATEGORIES=	math
MASTER_SITES=	http://wilkins.ne.mediaone.net/grpn/

MAINTAINER=	jedgar@fxp.org

USE_X_PREFIX=	yes
USE_GTK=	yes

ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grpn ${PREFIX}/bin

.include <bsd.port.mk>
