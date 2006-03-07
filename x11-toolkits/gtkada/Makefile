# New ports collection makefile for:   gtkada
# Date Created:			27 Nov 2000
# Whom:				Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gtkada
PORTVERSION=	1.2.12
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://cesnet.linux.tucows.com/files/ \
		http://aranea.linux.tucows.com/files/ \
		http://swissonline.linux.tucows.com/files/
DISTNAME=	GtkAda-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk binding for Ada

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat
LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

SHLIB_VERSION=	${PORTVERSION:S/1.2.//}

USE_X_PREFIX=	yes
USE_GNOME=	libcapplet libglade
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_SUB=	SHLIB_VERSION=${SHLIB_VERSION}

MAN1=	dgate.1 gate.1 gtkada-config.1

CONFLICTS=	zenity-[0-9]*

post-install:
	${INSTALL_DATA}	${WRKSRC}/docs/*.1 ${PREFIX}/man/man1/
	${LN} -sf ${PREFIX}/share/doc/GtkAda/*/*.info* ${PREFIX}/info/

.include <bsd.port.mk>
