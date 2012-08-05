# New ports collection makefile for:	bsd-splash-changer
# Date created:		11 Feb 2006
# Whom:			Martin Otto
#
# $FreeBSD$
#
# This port is self contained.
#

PORTNAME=	bsd-splash-changer
PORTVERSION=	060211
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	gamato@users.sf.net
COMMENT=	Boot Splash Image Changer

USE_RC_SUBR=	change_splash
SUB_FILES=	pkg-message
NO_BUILD=	yes

do-fetch:
	@${DO_NADA}

do-install:
	${MKDIR} ${DATADIR}

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
