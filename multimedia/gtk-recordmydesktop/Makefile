# $FreeBSD$

PORTNAME=	gtk-recordmydesktop
PORTVERSION=	0.3.8
PORTREVISION=	3
CATEGORIES=	multimedia deskutils
MASTER_SITES=	SF/recordmydesktop/gtk-recordMyDesktop/${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK+ frontend to recordMyDesktop

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/recordmydesktop:multimedia/recordmydesktop

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake pkgconfig python:2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gtk20 pygtk2
INSTALL_ICONS=	yes

post-build:
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/src/gtk-recordMyDesktop

.include <bsd.port.mk>
