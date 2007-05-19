# New ports collection makefile for:	emerald-themes
# Date created:				Oct 29 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emerald-themes
PORTVERSION=	0.2.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/beryl/

MAINTAINER=	rnoland@2hip.net
COMMENT=	Themes for the Emerald Window Decorator

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} 's|/bin/bash|${LOCALBASE}/bin/bash|' \
			${WRKSRC}/themes/import.sh

.include <bsd.port.mk>
