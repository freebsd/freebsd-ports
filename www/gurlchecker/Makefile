# New ports collection makefile for:	gURLChecker
# Date created:			06 Jun 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	gurlchecker
PORTVERSION=	0.8.1
CATEGORIES=	www gnome
MASTER_SITES=	http://labs.libre-entreprise.org/download.php/${DOWNNUM}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	A Gnome program to check a page/website for broken links

LIB_DEPENDS=	gnutls.12:${PORTSDIR}/security/gnutls \
		gnet-2.0.0:${PORTSDIR}/net/gnet2

USE_X_PREFIX=	yes
DOWNNUM=	373
USE_GNOME=	gnomeprefix gnomehack libgnomeui intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
