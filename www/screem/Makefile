# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION=	0.6.2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Nice GNOME/GTK-based HTML editor

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgnomeprintui libgtkhtml
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
USE_PERL5=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-ssl

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\@GNOME_DATA_PREFIX\@|\$$\(datadir\)|g'

.include <bsd.port.mk>
