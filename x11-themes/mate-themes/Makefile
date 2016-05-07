# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-themes
PORTVERSION=	3.18.1
CATEGORIES=	x11-themes mate
MASTER_SITES=	MATE/themes/${PORTVERSION:R}/
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of themes and icons for MATE

BUILD_DEPENDS=	gtk-engines2>=2.15.0:x11-themes/gtk-engines2 \
		icon-naming-utils>=0.8.7:x11-themes/icon-naming-utils
RUN_DEPENDS=	gtk-engines2>=2.15.0:x11-themes/gtk-engines2 \
		gtk-murrine-engine>=0.98:x11-themes/gtk-murrine-engine

PORTSCOUT=	limit:^${PORTVERSION:R:S|.|\.|}\.*$$

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_MATE=	marco
USE_GNOME=	gdkpixbuf2 gtk20 intlhack
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LOCALES=	as ast be@latin bn_IN ca@valencia cmn crh dz en@shaw fur \
		ku ky mai mg mr nds oc rw si sr@latin te ug xh zh_HK

post-install:
.for l in ${LOCALES}
	@rmdir ${STAGEDIR}${PREFIX}/share/locale/${l}/LC_MESSAGES
	@rmdir ${STAGEDIR}${PREFIX}/share/locale/${l}
.endfor

.include <bsd.port.mk>
