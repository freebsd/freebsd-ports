# New ports collection makefile for:	grdesktop
# Date created:				Jan 3 2003
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	grdesktop
PORTVERSION=	0.23
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	GNOME frontend for the remote desktop client (rdesktop)

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gnomeprefix gnomehack
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-keymap-path=${LOCALBASE}/share/rdesktop/keymaps

post-patch:
	@${REINPLACE_CMD} -e 's|^\(GETTEXT_PACKAGE =\).*|\1 grdesktop|' ${WRKSRC}/po/Makefile.in.in

MAN1=		grdesktop.1

.include <bsd.port.mk>
