# New ports collection makefile for:	mmc
# Date created:				21 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mmc
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	mail gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiny mail client for Gnome Desktop

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1//}

USE_GNOME=	gnomehack gnomelibs gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CFLAGS+=	-fpermissive

.include <bsd.port.mk>
