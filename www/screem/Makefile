# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION=	0.10.2
CATEGORIES=	www editors gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Nice GNOME/GTK-based HTML editor

LIB_DEPENDS+=	neon.24:${PORTSDIR}/www/neon \
		croco.3:${PORTSDIR}/textproc/libcroco

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgnomeprintui libgtkhtml \
		gtksourceview lthack intlhack
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes

.ifndef WITHOUT_OPENSSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl
.endif

USE_PERL5=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--without-included-neon

post-patch:
	@${REINPLACE_CMD} -e 's|\$${DATADIRNAME}/\$${PACKAGE}/pixmaps|\$${DATADIRNAME}/gnome/\$${PACKAGE}/pixmaps|g' \
		${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|\/\* #undef HAVE_LIMITS_H \*\/|#define HAVE_LIMITS_H 1|g' ${WRKSRC}/config.h

.include <bsd.port.mk>
