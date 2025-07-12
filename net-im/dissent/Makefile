PORTNAME=	dissent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.34
PORTREVISION=	4
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny native Discord app
WWW=		https://github.com/diamondburned/dissent

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libspelling-1.so:x11-toolkits/libspelling

USES=		gnome go:modules gstreamer pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk40 gtksourceview5 libadwaita
USE_GSTREAMER=	bad good ugly
GO_MODULE=	libdb.so/dissent
CGO_LDFLAGS+=	-Wl,--as-needed # gtk4 deps
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/so.libdb.dissent.desktop \
		share/dbus-1/services/so.libdb.dissent.service \
		share/icons/hicolor/scalable/apps/so.libdb.dissent.svg \
		share/metainfo/so.libdb.dissent.metainfo.xml

post-patch:
	@${REINPLACE_CMD} 's,/usr/bin,${PREFIX}/bin,' \
		${WRKSRC}/nix/*.service
	@${RM} ${WRKSRC}/vendor/libdb.so/gotk4-spelling/pkg/spelling/spelling-dictionary.go

post-install:
# Install extras similar to Nix flake
.for f in nix/*.desktop nix/*.service *.metainfo.xml \
	internal/icons/hicolor/scalable/apps/so.libdb.dissent.svg
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor

.include <bsd.port.mk>
