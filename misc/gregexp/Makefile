# ex:ts=8
# Ports collection makefile for:	gregexp
# Date created:			May 4, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gregexp
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	http://dentrassi.de/download/gregexp/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical regular expression explorer

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20 gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
