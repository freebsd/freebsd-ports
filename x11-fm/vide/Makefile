# New ports collection makefile for:	vide
# Date created:				May 17 2000
# Whom:					careilly
#
# $FreeBSD$
#

PORTNAME=	vide
PORTVERSION=	0.5
CATEGORIES=	x11-fm
MASTER_SITES=	http://vide.sourceforge.net/

MAINTAINER=	careilly@thecia.ie

RUN_DEPENDS=    vim:${PORTSDIR}/editors/vim5

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomelibs
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-DHAVE_SYS_PARAM_H"

PLIST_SUB=	VERSION=${PORTVERSION}

PATCH_WRKSRC=   ${WRKSRC}/src

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
