# New ports collection makefile for:	grdesktop
# Date created:				Jan 3 2003
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	grdesktop
PORTVERSION=	0.22
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	flz@xbsd.org
COMMENT=	GNOME frontend for the remote desktop client (rdesktop)

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gnomeprefix gnomehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|man_MANS = grdesktop.1|man_MANS =|' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
