# New ports collection makefile for:	rox-filer
# Date created:        13 November 2000
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox
PORTVERSION=	1.3.4
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=	rox-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${LOCALBASE}/share/mime/packages/freedesktop.org.xml:${PORTSDIR}/misc/shared-mime-info

MAN1=		rox.1

do-build:
	# Run the custom build procedure
	cd ${WRKSRC} && GTK_CONFIG=${GTK_CONFIG} GLIB_CONFIG=${GLIB_CONFIG} ROX-Filer/AppRun --compile

do-install:
	${MKDIR} ${PREFIX}/apps/ROX-Filer
	cd ${WRKSRC}/ROX-Filer && ${CP} -r .DirIcon Action.png AppInfo.xml AppRun FreeBSD-ix86 Help Messages Options.xml images style.css ${PREFIX}/apps/ROX-Filer
	cd ${WRKSRC} && ${CP} -r Choices ${PREFIX}/share/
	${MKDIR} ${PREFIX}/share/mime/mime-info
	${CAT} ${FILESDIR}/rox | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${PREFIX}/bin/rox
	${CHMOD} 775 ${PREFIX}/bin/rox
	${INSTALL_MAN} ${WRKSRC}/rox.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
