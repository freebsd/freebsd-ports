# New ports collection makefile for:	eazel-themes
# Date created:				17 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eazel-themes
PORTVERSION=	0.0.10101
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.//g}

MAINTAINER=	sobomax@altavista.net

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish \
		${X11BASE}/lib/gtk/themes/engines/libpixmap.so:${PORTSDIR}/x11-toolkits/gtk-engines

WRKSRC=		${WRKDIR}/${DISTNAME}/gtk+/eazel-engine

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes
AUTOMAKE_ARGS=	--add-missing

post-extract:
	@find ${WRKSRC}/../.. | xargs ${CHOWN} root:wheel
	@find ${WRKSRC}/../.. -type f | xargs ${CHMOD} 644
	@find ${WRKSRC}/../.. -type d | xargs ${CHMOD} 755

post-install:
	${MKDIR} ${PREFIX}/share/themes/Eazel
	${MKDIR} ${PREFIX}/share/sawfish/themes/Eazel
	cd ${WRKSRC}/.. && ${TAR} -chf - Eazel | \
		${TAR} --unlink -xf - -C ${PREFIX}/share/themes
	cd ${WRKSRC}/../../sawfish &&  ${TAR} -chf - Eazel Ice | \
		${TAR} --unlink -xf - -C ${PREFIX}/share/sawfish/themes

.include <bsd.port.mk>
