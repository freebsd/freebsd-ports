# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/mail/evolution-mapi3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	evolution-mapi
PORTVERSION=	3.6.3
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution plugin to connect to Microsoft Exchange servers

BUILD_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution
LIB_DEPENDS=	libmapi.so:${PORTSDIR}/mail/libmapi
RUN_DEPENDS=	evolution>=${EVO_VER}:${PORTSDIR}/mail/evolution

BROKEN=		needs newer libmapi which needs samba4 update.

EVO_VER=	3.6.3
USE_XZ=		yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gconf2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS"=	-L${LOCALBASE}/lib

VERSION=	3.0
PLIST_SUB=	VERSION=${VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/libexchangemapi/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
