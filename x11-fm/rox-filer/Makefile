# New ports collection makefile for:	rox-filer
# Date created:        13 November 2000
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox
PORTVERSION=	1.1.12
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=	rox-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=    gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		xml.5:${PORTSDIR}/textproc/libxml
RUN_DEPENDS=	${LOCALBASE}/share/Choices:${PORTSDIR}/x11-fm/rox-base

USE_GTK=	yes
MAN1=		rox.1

do-build:
	# Run the custom build procedure
	cd ${WRKSRC} && GTK_CONFIG=${GTK_CONFIG} GLIB_CONFIG=${GLIB_CONFIG} ROX-Filer/AppRun --compile

do-install:
	${MKDIR} ${PREFIX}/apps/ROX-Filer
	cd ${WRKSRC}/ROX-Filer && ${CP} -r Options.xml AppIcon.xpm FreeBSD-ix86 Messages AppRun Help pixmaps Styles ${PREFIX}/apps/ROX-Filer
	${CAT} ${FILESDIR}/rox | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${PREFIX}/bin/rox
	${CHMOD} 775 ${PREFIX}/bin/rox
	${INSTALL_MAN} ${WRKSRC}/rox.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
