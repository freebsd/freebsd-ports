PORTNAME=	gonepass
DISTVERSION=	g20181221
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ 1Password reader

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang gnome pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	jbreams
GH_TAGNAME=	3da5cfa120
USE_GNOME=	gtk30 gtkmm30

INSTALLS_ICONS=	yes

PLIST_FILES=	bin/gonepass \
		share/applications/gonepass.desktop \
		share/pixmaps/gonepass.png

.include <bsd.port.mk>
