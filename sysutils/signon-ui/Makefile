PORTNAME=	signon-ui
# Note, we're counting since the 0.17+15.10.20150810-0ubuntu1 tag:
# > git rev-list 0.17+15.10.20150810-0ubuntu1.. --count
DISTVERSION=	0.17-355
DISTVERSIONSUFFIX=	-g4368bb7
PORTREVISION=	4
CATEGORIES=	sysutils kde
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Component for handling accounts-sso user interactions
WWW=		https://gitlab.com/accounts-sso/signon-ui

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-qt5.so:net-im/libaccounts-qt@qt5 \
		libnotify.so:devel/libnotify \
		libsignon-qt5.so:sysutils/signond@qt5 \
		libproxy.so:net/libproxy

USES=		compiler:c++11-lang gettext-runtime gl gnome pkgconfig python \
		qmake qt:5 tar:bz2
USE_GL=		gl
USE_GNOME=	gdkpixbuf2 glib20
USE_QT=		core dbus declarative gui location network webchannel webengine widgets xml \
		buildtools:build qmake:build
# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	4368bb77d9d1abc2978af514225ba4a42c29a646

.include <bsd.port.mk>
