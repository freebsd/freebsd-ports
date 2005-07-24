# New ports collection makefile for:	eiciel
# Date created:				July 20, 2005
# Whom:					andreas@syndrom23.de
#
# $FreeBSD$
#

PORTNAME=	eiciel
PORTVERSION=	0.7
CATEGORIES=	sysutils security
MASTER_SITES=	http://rofi.pinchito.com/eiciel/download/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	A GNOME-based ACL editor, with integration into Nautilus

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15

MAN1=		eiciel.1

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.else
PLIST_SUB+=	NLS=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Needs ACL support available in FreeBSD 5.0 and later
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^libeiciel_nautilus_la_LDFLAGS/ s|= |= -avoid-version -module |' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
