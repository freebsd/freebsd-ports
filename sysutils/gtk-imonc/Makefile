# New ports collection makefile for:	gtk-imonc
# Date Created:				26. October 2002
# Whom:					Steffen Vogelreuter
#
# $FreeBSD$
#

PORTNAME=	gtk-imonc
PORTVERSION=	0.6.2
CATEGORIES=	sysutils
MASTER_SITES=	http://userpage.fu-berlin.de/~zeank/gtk-imonc/download/

MAINTAINER=	aberg@doomnet.de
COMMENT=	A GTK2-based imond-client to control an on(e) disc fli4l router

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes

.include <bsd.port.mk>
