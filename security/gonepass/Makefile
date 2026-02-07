PORTNAME=	gonepass
DISTVERSION=	g20181221
PORTREVISION=	5
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK 1Password reader
WWW=		https://github.com/jbreams/gonepass

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang gnome pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	jbreams
GH_TAGNAME=	3da5cfa120
USE_GNOME=	gtk30 gtkmm30

PLIST_FILES=	bin/gonepass \
		share/applications/gonepass.desktop \
		share/pixmaps/gonepass.png

.include <bsd.port.mk>
