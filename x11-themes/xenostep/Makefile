# New ports collection makefile for:	xenostep
# Date Created:				14 November 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xenostep
PORTVERSION=	200011270836
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	gtk
DISTNAME=	XenoStep-1.2.x-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/XenoStep

USE_X_PREFIX=	yes
USE_GTK=	yes
ALL_TARGET=	# empty
MAKE_ENV=	MKDIR="${MKDIR}"

DIRS=		"XenoStep Classic" "XenoStep Classic Small" "XenoStep HeliX" \
		"XenoStep HeliX Small" "XenoStep Modern" "XenoStep Modern Small"

post-extract:
	for dir in ${DIRS}; do \
		destdir=`${ECHO} $${dir} | ${SED} 's| |_|g'`; \
		${CP} -R "${WRKSRC}/$${dir}" "${WRKSRC}/$${destdir}"; \
	done

.include <bsd.port.mk>
