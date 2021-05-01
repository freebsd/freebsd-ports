# Created by: eric

PORTNAME=	stardict
PORTVERSION=	3.0.6
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/stardict-4/${PORTVERSION}
DIST_SUBDIR=	stardict

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Dictionary lookup program written in Gtk2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20 \
		libenchant.so:textproc/enchant
RUN_DEPENDS=	xdg-open:devel/xdg-utils

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-festival \
		--disable-gucharmap \
		--disable-espeak \
		--disable-tools \
		--disable-updateinfo \
		--disable-advertisement \
		--disable-gnome-support \
		--disable-schemas-install \
		--disable-scrollkeeper

USES=		compiler:c++11-lang gettext gmake gnome libtool localbase \
		pathfix pkgconfig tar:bzip2
USE_CXXSTD=	c++11
USE_GNOME=	intltool gtk20

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,g' \
		${WRKSRC}/dict/src/conf.cpp
	@${REINPLACE_CMD} \
		-e '/as_fn_error.*gnome-doc-utils/d' \
		-e '/DEP_MODULES=/s/"$$/ gmodule-2.0"/' \
		${WRKSRC}/dict/configure
	${REINPLACE_CMD} -e '/^SUBDIRS/s,help,,' ${WRKSRC}/dict/Makefile.in

.include <bsd.port.mk>
