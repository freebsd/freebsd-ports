# New ports collection makefile for:	pmail
# Date created:				27 July 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pmail
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	mail python gnome
MASTER_SITES=	http://www.toad.net/~sbender/pmail/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome
RUN_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	yes

.include <bsd.port.mk>
