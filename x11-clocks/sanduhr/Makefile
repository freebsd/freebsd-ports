# New ports collection makefile for:	sanduhr
# Date created:				14 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sanduhr
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-clocks gnome
MASTER_SITES=	http://seehuhn.de/data/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An alarm clock for GNOME desktop designed as a sand-glass

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomelibs gnometarget gnomeprefix oaf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		sanduhr.1

.include <bsd.port.mk>
