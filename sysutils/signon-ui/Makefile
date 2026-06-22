PORTNAME=	signon-ui
# Note, we're counting since the 0.17+15.10.20150810-0ubuntu1 tag:
# > git rev-list 0.17+15.10.20150810-0ubuntu1.. --count
DISTVERSION=	0.17-368
DISTVERSIONSUFFIX=	-geef943f
CATEGORIES=	sysutils kde
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Component for handling accounts-sso user interactions
WWW=		https://gitlab.com/accounts-sso/signon-ui

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-qt6.so:net-im/libaccounts-qt \
		libnotify.so:devel/libnotify \
		libsignon-qt6.so:sysutils/signond \
		libproxy.so:net/libproxy

USES=		gettext-runtime gl gnome pkgconfig python \
		qmake qt:6 tar:bz2
USE_GL=		gl
USE_GNOME=	gdkpixbuf glib20
USE_QT=		base declarative positioning webchannel webengine
# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	eef943f0edf3beee8ecb85d4a9dae3656002fc24

.include <bsd.port.mk>
