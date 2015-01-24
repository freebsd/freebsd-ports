# Created by: ports@c0decafe.net <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	gpass
PORTVERSION=	0.5.1
PORTREVISION=	11
CATEGORIES=	security gnome
MASTER_SITES=	http://projects.netlab.jp/gpass/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password manager for GNOME2

LIB_DEPENDS=	libmcrypt.so:${PORTSDIR}/security/libmcrypt \
		libmhash.so:${PORTSDIR}/security/mhash

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic

USES=		desktop-file-utils gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk20 libgnomeui intltool libglade2
GCONF_SCHEMAS=	gpass.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|{packageprefix}/share|{datadir}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/include/gpass/error.h \
		${WRKSRC}/src/helper.h

.include <bsd.port.mk>
