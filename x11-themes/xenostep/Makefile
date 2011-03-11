# New ports collection makefile for:	xenostep
# Date Created:				14 November 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/xenostep/Makefile,v 1.1 2006/07/20 11:38:28 ahze Exp $

PORTNAME=	xenostep
PORTVERSION=	200011270836
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	xenostep
DISTNAME=	${PORTNAME}-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ theme engine based on the Xenophilia and Interface engines

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/XenoStep

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
