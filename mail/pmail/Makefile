# New ports collection makefile for:	pmail
# Date created:				27 July 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pmail
PORTVERSION=	0.5.3
PORTREVISION=	3
CATEGORIES=	mail python gnome
MASTER_SITES=	# previous mastersites disappeared in 2001 and 2002

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME/python email client

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
