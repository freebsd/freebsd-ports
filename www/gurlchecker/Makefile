# New ports collection makefile for:	gURLChecker
# Date created:			06 Jun 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	gurlchecker
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://labs.libre-entreprise.org/download.php/57/
MASTER_SITE_SUBDIR=	${PORTNAME}/stable/0.6

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	A Gnome program to check a page/website for broken links

USE_X_PREFIX=	yes

USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
