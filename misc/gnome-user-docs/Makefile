PORTNAME=	gnome-user-docs
PORTVERSION=	47.6
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME user documentation
WWW=		https://gitlab.gnome.org/GNOME/gnome-user-docs

LICENSE=	CC-BY-3.0
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	itstool:textproc/itstool

USES=		gettext-tools gmake gnome pathfix tar:xz
USE_GNOME=	libxml2:build
GNU_CONFIGURE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
