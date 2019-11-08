# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-themes
PORTVERSION=	3.22.14
CATEGORIES=	x11-themes mate
MASTER_SITES=	MATE/themes/${PORTVERSION:R}/
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of themes and icons for MATE

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	gtk-engines2>=2.15.0:x11-themes/gtk-engines2 \
		gtk-murrine-engine>=0.98:x11-themes/gtk-murrine-engine

PORTSCOUT=	limit:^${PORTVERSION:R:S|.|\.|}\.*$$

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

LOCALES=	as ast bn_IN ca@valencia cmn crh dz es_CO fur fy \
		hy kk ky mai mg mr nds oc si sr@latin te ug xh zh_HK

post-install:
.for l in ${LOCALES}
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/${l}/LC_MESSAGES
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/locale/${l}
.endfor

.include <bsd.port.mk>
