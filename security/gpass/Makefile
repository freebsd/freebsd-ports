# Created by: ports@c0decafe.net <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	gpass
PORTVERSION=	0.5.1
PORTREVISION=	11
CATEGORIES=	security gnome
MASTER_SITES=	https://github.com/raffael-sfm/gpass/releases/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password manager for GNOME2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmcrypt.so:security/libmcrypt \
		libmhash.so:security/mhash

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic

USES=		desktop-file-utils gmake pathfix pkgconfig
USE_GNOME=	gtk20 intltool libglade2 libgnomeui
GCONF_SCHEMAS=	gpass.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|{packageprefix}/share|{datadir}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/include/gpass/error.h \
		${WRKSRC}/src/helper.h

.include <bsd.port.mk>
