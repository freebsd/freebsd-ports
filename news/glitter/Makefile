# New ports collection makefile for:	glitter
# Date Created:		09 Dec 2000
# Whom:			Greg Greenaae <greg@gregnet.net>
#
# $FreeBSD$
#

PORTNAME=	glitter
PORTVERSION=	1.0.b.1
CATEGORIES=	news
MASTER_SITES=	http://mews.org.uk/glitter/\
		ftp://ftp.gregnet.net/pub/FreeBSD/ports/news/glitter/
DISTNAME=	${PORTNAME}-1.0beta1

MAINTAINER=	greg@gregnet.net

USE_X_PREFIX=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.endif

.include <bsd.port.mk>
