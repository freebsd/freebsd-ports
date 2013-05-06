# Created by: andreas@syndrom23.de
# $FreeBSD$

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
USES=		pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack nautilus2 libgnomeui

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-nautilus-extensions-dir=${PREFIX}/lib/nautilus/extensions-2.0
MAKE_JOBS_SAFE=	yes

MAN1=		eiciel.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
