# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.screem.org/src/ \
		http://www.borgsdemons.com/distfiles/screem/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-docs${EXTRACT_SUFX}

MAINTAINER=	coop9211@uidaho.edu

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomevfs gtkhtml
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include/gnome-vfs-1.0" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gnomevfs --with-ssl --with-included-neon

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${REINPLACE_CMD} -e \
		's|\@GNOME_DATA_PREFIX\@|\$$\(datadir\)|g'

post-install:
	@${INSTALL_DATA} ${WRKSRC}/../${PORTNAME}-docs/* \
		${PREFIX}/share/gnome/help/screem/C/

.include <bsd.port.mk>
