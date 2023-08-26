PORTNAME=	equinox
PORTVERSION=	1.50
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	LOCAL/grembo
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine
DISTFILES=	121881-${DISTNAME}.tar.gz \
		140449-${PORTNAME}-themes-${PORTVERSION}.tar.gz

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Equinox GTK 2.x engine and themes
WWW=		http://gnome-look.org/content/show.php?content=121881

LICENSE=	GPLv2

BUILD_DEPENDS=	gtk-engines2>=2.15.0:x11-themes/gtk-engines2 \
		icon-naming-utils>=0.8.7:x11-themes/icon-naming-utils
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	gtk-engines2>=2.15.0:x11-themes/gtk-engines2

USES=		gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
DATADIR=	${PREFIX}/share/themes
WRKSRC=		${WRKDIR}/equinox-${PORTVERSION}

SUBDIRS=	"Equinox Evolution" "Equinox Evolution Dawn" \
		"Equinox Evolution Dawn" "Equinox Evolution Dusk" \
		"Equinox Evolution Light" "Equinox Evolution Midnight" \
		"Equinox Evolution Rounded" "Equinox Evolution Squared"
EXAMPLES=	"Equinox Evolution.crx" "Equinox Evolution Dawn.crx" \
		"Equinox Evolution Dusk.crx" "Equinox Evolution Midnight.crx"

OPTIONS_DEFINE=			ANIMATION DOCS EXAMPLES
OPTIONS_DEFAULT=		ANIMATION
ANIMATION_DESC=			Enable animation support
ANIMATION_CONFIGURE_ENABLE=	animation

post-patch:
	@${FIND} ${WRKDIR} -name 'gtkrc' -exec \
	    ${REINPLACE_CMD} -e 's!^include "apps/nautilus\.rc"!#&!' {} +
	@${FIND} ${WRKDIR} -type f -name 'gtkrc.bak' -exec ${RM} {} +
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/animation.c

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in ${SUBDIRS}
	${CP} -R ${WRKDIR}/${i} ${STAGEDIR}${DATADIR}
.endfor
	${FIND} ${STAGEDIR}${DATADIR} -type d -exec ${CHMOD} 755 {} +
	${FIND} ${STAGEDIR}${DATADIR} -type f -exec ${CHMOD} ${SHAREMODE} {} +

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKDIR}/$i ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
