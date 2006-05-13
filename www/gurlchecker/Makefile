# New ports collection makefile for:	gURLChecker
# Date created:			06 Jun 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	gurlchecker
PORTVERSION=	0.8.3
CATEGORIES=	www gnome
MASTER_SITES=	http://labs.libre-entreprise.org/frs/download.php/%SUBDIR%/
MASTER_SITE_SUBDIR=	423

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Gnome program to check a page/website for broken links

LIB_DEPENDS=	gnutls.15:${PORTSDIR}/security/gnutls \
		gnet-2.0.0:${PORTSDIR}/net/gnet2

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc ui man|ui|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-lresolv||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
