# New ports collection makefile for:	vide
# Date created:				May 17 2000
# Whom:					careilly
#
# $FreeBSD$
#

PORTNAME=	vide
PORTVERSION=	0.2.6
CATEGORIES=	x11-fm
MASTER_SITES=	http://vide.sourceforge.net/

MAINTAINER=	careilly@thecia.ie

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-DHAVE_SYS_PARAM_H"

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
