# New ports collection makefile for:	wmcalc
# Date created:				28 March 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmcalc
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	math windowmaker
MASTER_SITES=	http://members.cox.net/ehf_dockapps/wmcalc/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= jedgar

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple dockable calculator

ALL_TARGET=	clean wmcalc
PLIST_FILES=	bin/wmcalc
USE_XORG=   xpm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcalc ${PREFIX}/bin

.include <bsd.port.mk>
