# ex:ts=8
# Ports collection makefile for:	gregexp
# Date created:			May 4, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gregexp
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://dentrassi.de/download/gregexp/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical regular expression explorer

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
