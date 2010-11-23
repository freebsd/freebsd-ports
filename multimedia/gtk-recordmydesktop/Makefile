# New ports collection makefile for:	gtk-recordmydesktop
# Date created:				2010-07-16
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gtk-recordmydesktop
PORTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	multimedia deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	recordmydesktop/gtk-recordMyDesktop/${PORTVERSION}

MAINTAINER=	cvs-src@yandex.ru
COMMENT=	GTK+ frontend to recordMyDesktop

RUN_DEPENDS=	${LOCALBASE}/bin/recordmydesktop:${PORTSDIR}/multimedia/recordmydesktop

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_PYTHON=	yes
USE_GNOME=	gtk20 pygtk2 desktopfileutils
INSTALL_ICONS=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

post-build:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/gtk-recordMyDesktop

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
