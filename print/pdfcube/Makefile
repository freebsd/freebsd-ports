# New ports collection makefile for:	pdfcube
# Date created:		Apr. 20, 2007
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdfcube
PORTVERSION=	0.0.2
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://code.100allora.it/releases/pdfcube/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	An OpenGL presentation viewer on a spinning cube

LIB_DEPENDS=	gtkglext:${PORTSDIR}/x11-toolkits/gtkglext \
		poppler-glib:${PORTSDIR}/graphics/poppler-gtk

USE_GL=		glut
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/pdfcube

.include <bsd.port.mk>
