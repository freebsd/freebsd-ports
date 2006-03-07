# New ports collection makefile for:	glacier
# Date created:		30 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	glacier
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	mail gnome
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another GNOME mail user agent

DEPRECATED=	mastersite disappeared, no longer maintained by author
EXPIRATION_DATE=	2006-03-31

PLIST_FILES=	bin/glacier
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|$$(datadir)/|g'

.include <bsd.port.mk>
