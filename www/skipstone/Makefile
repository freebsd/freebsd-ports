# New ports collection makefile for:	SkipStone
# Date created:				16 November 2000
# Whom:					eric <eric@osd.bsdi.com>
#
# $FreeBSD$
#

PORTNAME=	skipstone
PORTVERSION=	0.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	eric@osd.bsdi.com

BUILD_DEPENDS=	${X11BASE}/include/mozilla/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers \
		${X11BASE}/lib/mozilla-embedded/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-embedded
RUN_DEPENDS=	${X11BASE}/lib/mozilla-embedded/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-embedded

USE_GTK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${PERL} -pi -e 's#/usr/local#${PREFIX}#' ${WRKSRC}/src/skipstone.h ${WRKSRC}/src/skipstone
	@${PERL} -pi -e 's#/usr/share#${PREFIX}/share#' ${WRKSRC}/src/skipstone.h

.include <bsd.port.mk>
