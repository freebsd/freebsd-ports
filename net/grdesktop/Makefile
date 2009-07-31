# New ports collection makefile for:	grdesktop
# Date created:				Jan 3 2003
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	grdesktop
PORTVERSION=	0.23
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	GNOME frontend for the remote desktop client (rdesktop)

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gnomeprefix gnomehack
GCONF_SCHEMAS=	grdesktop.schemas
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-keymap-path=${LOCALBASE}/share/rdesktop/keymaps

MAN1=		grdesktop.1

post-patch:
	@${REINPLACE_CMD} -e 's|^\(GETTEXT_PACKAGE =\).*|\1 grdesktop|' ${WRKSRC}/po/Makefile.in.in

post-install:
	@${INSTALL_DATA} ${PREFIX}/share/pixmaps/grdesktop/icon.png ${PREFIX}/share/pixmaps/grdesktop.png

.include <bsd.port.mk>
