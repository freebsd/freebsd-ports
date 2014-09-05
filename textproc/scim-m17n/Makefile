# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	scim-m17n
PORTVERSION=	0.2.3
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	SCIM IMEngine module which uses m17n library as the backend

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim \
		gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	libm17n.so:${PORTSDIR}/devel/m17n-lib
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim

USES=		gmake pkgconfig libtool:keepla
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/scim-1.0/1.4.0/IMEngine/m17n.a \
		lib/scim-1.0/1.4.0/IMEngine/m17n.la \
		lib/scim-1.0/1.4.0/IMEngine/m17n.so \
		share/scim/icons/scim-m17n.png

post-patch:
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(moduledir)|${STAGEDIR}${PREFIX}/lib/scim-1.0/1.4.0/IMEngine|g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(icondir)|${STAGEDIR}${PREFIX}/share/scim/icons|g' \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
