# ex:ts=8
# Ports collection makefile for:  stow
# Date created:			  6 June 2000
# Whom:				  Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	stow
PORTVERSION=	1.3.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	cyrille.lefevre@laposte.net

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
# PREFIX isn't honored. force it w/ prefix.
MAKE_ARGS=	prefix="${PREFIX}"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/stow ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/stow.info ${PREFIX}/info
	@install-info ${PREFIX}/info/stow.info ${PREFIX}/info/dir

.include <bsd.port.mk>
