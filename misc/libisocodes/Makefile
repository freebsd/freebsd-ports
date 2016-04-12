# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libisocodes
PORTVERSION=	1.2.2
CATEGORIES=	misc
MASTER_SITES=	http://pkg-isocodes.alioth.debian.org/downloads/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Interaction library for iso-codes

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2
INSTALL_TARGET=	install-strip

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/xml/|${LOCALBASE}/share/xml/|g' \
		${WRKSRC}/src/iso_15924.* ${WRKSRC}/src/iso_3166* \
		${WRKSRC}/src/iso_4217.* ${WRKSRC}/src/iso_639* \
		${WRKSRC}/src/isocodes.* ${WRKSRC}/tests/test_iso_*.vala

.include <bsd.port.mk>
