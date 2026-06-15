PORTNAME=	mate-user-guide
DISTVERSION=	1.28.0
PORTREVISION=	2
CATEGORIES=	misc mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE users guide

LICENSE=	GFDL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		intltool>=0.40.0:textproc/intltool
RUN_DEPENDS=	yelp:x11/yelp

USES=		gettext gmake tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
PORTSCOUT=	site:https://github.com/mate-desktop/mate-user-guide/releases/ limitw:1,even
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
