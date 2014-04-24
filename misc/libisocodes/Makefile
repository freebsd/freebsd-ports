# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libisocodes
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://pkg-isocodes.alioth.debian.org/downloads/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Interaction library for iso-codes

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libgee.so:${PORTSDIR}/devel/libgee06
RUN_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomehier introspection:build libxml2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/xml/|${LOCALBASE}/share/xml/|g' \
		${WRKSRC}/src/iso_15924.* ${WRKSRC}/src/iso_3166* \
		${WRKSRC}/src/iso_4217.* ${WRKSRC}/src/iso_639* \
		${WRKSRC}/src/isocodes.* ${WRKSRC}/tests/test_iso_*.vala

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libisocodes.so.0.0.0

.include <bsd.port.mk>
