# New ports collection makefile for:	skipstone
# Date created:				16 November 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	skipstone
PORTVERSION=	0.7.8
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	eric@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/mozilla/gtkembedmoz/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers \
		${X11BASE}/lib/mozilla-embedded/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-embedded
RUN_DEPENDS=	${X11BASE}/lib/mozilla-embedded/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-embedded \
		wget:${PORTSDIR}/ftp/wget

USE_GTK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${PERL} -pi -e 's#/usr/local#${X11BASE}#' ${WRKSRC}/src/skipstone.h
	@${PERL} -pi -e 's#X11BASE#${X11BASE}#' ${WRKSRC}/src/skipstone

.include <bsd.port.mk>
