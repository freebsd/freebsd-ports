PORTNAME=	gnome-keyring-sharp
PORTVERSION=	1.0.2
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	http://www.go-mono.com/archive/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fully managed implementation of gnome-keyring
WWW=		https://andrew.jorgensenfamily.us/2008/08/gnome-keyring-sharp/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:devel/ndesk-dbus \
		${LOCALBASE}/libdata/pkgconfig/gnome-keyring-1.pc:security/libgnome-keyring
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		autoreconf gmake gnome libtool mono pathfix pkgconfig
USE_GNOME=	gtksharp20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
