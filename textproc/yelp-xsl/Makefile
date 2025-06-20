PORTNAME=	yelp-xsl
DISTVERSION=	42.4
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DocBook XSLT stylesheets for yelp
WWW=		https://gitlab.gnome.org/GNOME/yelp-xsl

LICENSE=	GPLv2+ LGPL21+ MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	itstool:textproc/itstool \
		bash:shells/bash

USES=		gettext gnome localbase meson pkgconfig shebangfix \
		tar:xz
USE_GNOME=	libxml2 libxslt
SHEBANG_FILES=	xslt/common/domains/gen_yelp_xml.sh
NO_ARCH=	yes

.include <bsd.port.mk>
