# New ports collection makefile for:	xenostep
# Date Created:				14 November 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xenostep
PORTVERSION=	200011270836
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR= xenostep
DISTNAME=	${PORTNAME}-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ theme engine based on the Xenophilia and Interface engines

WRKSRC=		${WRKDIR}/XenoStep

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
ALL_TARGET=	# empty
MAKE_ENV=	MKDIR="${MKDIR}"

DIRS=		"XenoStep Classic" "XenoStep Classic Small" "XenoStep HeliX" \
		"XenoStep HeliX Small" "XenoStep Modern" "XenoStep Modern Small"

post-extract:
	for dir in ${DIRS}; do \
		destdir=`${ECHO_CMD} $${dir} | ${SED} 's| |_|g'`; \
		${CP} -R "${WRKSRC}/$${dir}" "${WRKSRC}/$${destdir}"; \
	done

.include <bsd.port.mk>
