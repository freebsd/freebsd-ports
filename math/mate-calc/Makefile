# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-calc
PORTVERSION=	1.6.0
CATEGORIES=	math mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE calculator tool based on the old calctool for OpenWindows

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack
USE_GNOME=	glib20 gnomehier gtk20 libxml2
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.calc.gschema.xml

post-configure:
	@${REINPLACE_CMD} -e '/^DATADIRNAME/s/lib/share/' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
