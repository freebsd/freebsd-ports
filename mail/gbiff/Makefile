# New ports collection makefile for:   gbiff
# Date created:        31 March 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gbiff
PORTVERSION=	3.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|`gtk-config --cflags`|`\$$GTK_CONFIG --cflags`|g ; \
		 s|`gtk-config --libs`|`\$$GTK_CONFIG --libs`|g ; \
		 s|gnomeui --cflags|gnomeui applets --cflags|g ; \
		 s|DATADIRNAME}"|DATADIRNAME}/gnome"|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
