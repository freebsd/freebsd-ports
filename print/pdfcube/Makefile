# New ports collection makefile for:	pdfcube
# Date created:		Apr. 20, 2007
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdfcube
PORTVERSION=	0.0.2
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	# http://code.100allora.it/pdfcube/attachment/wiki/WikiStart/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	An OpenGL presentation viewer on a spinning cube

LIB_DEPENDS=	glut:${PORTSDIR}/graphics/libglut \
		gtkglext:${PORTSDIR}/x11-toolkits/gtkglext \
		poppler-glib:${PORTSDIR}/graphics/poppler-gtk

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pdfcube

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	${FETCH_CMD} -o "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" "http://code.100allora.it/pdfcube/attachment/wiki/WikiStart/${DISTNAME}${EXTRACT_SUFX}?format=raw"
.endif

.include <bsd.port.post.mk>
