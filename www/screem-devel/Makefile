# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Nice GNOME/GTK-based HTML editor

LIB_DEPENDS+=	neon.24:${PORTSDIR}/www/neon

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgnomeprintui libgtkhtml \
		gtksourceview
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.ifndef WITHOUT_OPENSSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl
.endif

USE_PERL5=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--without-included-neon
#			--with-neon="${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\@GNOME_DATA_PREFIX\@|\$$\(datadir\)|g'

post-configure:
	@${REINPLACE_CMD} -e 's|\/\* #undef HAVE_LIMITS_H \*\/|#define HAVE_LIMITS_H 1|g' ${WRKSRC}/config.h

.include <bsd.port.mk>
