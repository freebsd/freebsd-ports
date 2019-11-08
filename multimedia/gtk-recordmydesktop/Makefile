# $FreeBSD$

PORTNAME=	gtk-recordmydesktop
PORTVERSION=	0.3.8
PORTREVISION=	5
CATEGORIES=	multimedia deskutils
MASTER_SITES=	SF/recordmydesktop/gtk-recordMyDesktop/${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK+ frontend to recordMyDesktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	recordmydesktop:multimedia/recordmydesktop

NO_ARCH=	yes
GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake gnome localbase pkgconfig \
		python:2.7 shebangfix
SHEBANG_FILES=	src/gtk-recordMyDesktop.in
USE_GNOME=	gtk20 pygtk2
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
