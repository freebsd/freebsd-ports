# New ports collection makefile for:	eiciel
# Date created:				July 20, 2005
# Whom:					andreas@syndrom23.de
#
# $FreeBSD$
#

PORTNAME=	eiciel
PORTVERSION=	0.9.8.1
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	http://rofi.roger-ferrer.org/eiciel/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME-based ACL editor, with integration into Nautilus

LICENSE=	GPLv2

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack nautilus2 libgnomeui

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_PKGCONFIG=	build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-nautilus-extensions-dir=${PREFIX}/lib/nautilus/extensions-2.0
MAKE_JOBS_SAFE=	yes

MAN1=		eiciel.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
