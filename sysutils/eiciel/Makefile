# New ports collection makefile for:	eiciel
# Date created:				July 20, 2005
# Whom:					andreas@syndrom23.de
#
# $FreeBSD$
#

PORTNAME=	eiciel
PORTVERSION=	0.9.5.1
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	http://rofi.roger-ferrer.org/eiciel/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME-based ACL editor, with integration into Nautilus

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack nautilus2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-nautilus-extensions-dir=${PREFIX}/lib/nautilus/extensions-2.0
MAN1=		eiciel.1

post-patch:
	@${REINPLACE_CMD} -e '/^libeiciel_nautilus_la_LDFLAGS/ s|= |= -avoid-version -module |' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
