PORTNAME=	webkit2gtk3
PORTVERSION=	2.54.0
DISTVERSIONSUFFIX=	-1.el9_8
CATEGORIES=	www linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Web content engine for GTK (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://webkitgtk.org/

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	atk cairo dri enchant2 fontconfig freetype gdkpixbuf2 \
		gstreamer1 gtk3 harfbuzz harfbuzz-icu hyphen icu \
		imageformats-libs lcms2 libdrm libepoxy libgcrypt libseccomp \
		libsecret libtasn1 libxml2 libxslt pango systemd-libs \
		wayland webkit2gtk3-jsc xorglibs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/webkit2-gtk/pkg-descr

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
