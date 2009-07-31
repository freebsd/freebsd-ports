# New ports collection makefile for:	gtk-imonc
# Date Created:				26. October 2002
# Whom:					Steffen Vogelreuter
#
# $FreeBSD$
#

PORTNAME=	gtk-imonc
PORTVERSION=	0.6.4.1
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://userpage.fu-berlin.de/~zeank/gtk-imonc/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK2-based imond-client to control an on(e) disc fli4l router

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	gtk20 gnomehier

post-patch:
	@${REINPLACE_CMD} -e 's|<endian.h>|<sys/endian.h>|' \
		${WRKSRC}/src/md5.h

.include <bsd.port.mk>
