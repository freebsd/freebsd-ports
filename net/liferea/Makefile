# Ports collection Makefile for:	liferea
# Date created:		28 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liferea
PORTVERSION=	0.4.6b
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	liferea

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gconf2 libxml2 libgtkhtml \
		gnomevfs2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
