# ports collection makefile for:	gevas
# Date created:				19 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gevas
PORTVERSION=	0.0.0
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment
DISTNAME=	${PORTNAME}_alpha

MAINTAINER=	ishmael27@home.com

LIB_DEPENDS=	evas.0:${PORTSDIR}/graphics/evas

USE_GTK=	yes
USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
.for a in install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake/${a} ${WRKSRC}
.endfor

post-install:
	@strip ${PREFIX}/lib/libgevas.so.0

.include <bsd.port.mk>
