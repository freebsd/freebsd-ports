# New ports collection makefile for:	eazel-themes
# Date created:				17 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eazel-themes
PORTVERSION=	0.0.10207
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.//g}

MAINTAINER=	sobomax@altavista.net

RUN_DEPENDS=	sawfish:${PORTSDIR}/x11-wm/sawfish \
		${X11BASE}/lib/gtk/themes/engines/libpixmap.so:${PORTSDIR}/x11-toolkits/gtk-engines

WRKSRC=		${WRKDIR}/${DISTNAME}/gtk+/eazel-engine

USE_GNOMECTRL=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${X11BASE}/share \
		--datadir=${X11BASE}/share

post-extract:
	@find ${WRKSRC}/../.. -type f | grep -v eazel-engine | xargs ${CHMOD} 644
	@find ${WRKSRC}/../.. -type d | xargs ${CHMOD} 755

post-install:
	${MKDIR} ${PREFIX}/share/themes/Eazel
	${MKDIR} ${PREFIX}/share/sawfish/themes/Eazel
	cd ${WRKSRC}/.. && ${TAR} -chf - Eazel | \
		${TAR} --unlink -xf - -C ${PREFIX}/share/themes
	cd ${WRKSRC}/../../sawfish &&  ${TAR} -chf - Eazel Ice | \
		${TAR} --unlink -xf - -C ${PREFIX}/share/sawfish/themes
#	${LN} -sf ${PREFIX}/share/gnome/apps/Settings/Desktop/eazel-engine-properties.desktop \
#		${PREFIX}/share/gnome/control-center/Desktop/

.include <bsd.port.mk>
