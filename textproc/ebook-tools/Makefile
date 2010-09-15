# New ports collection makefile for:	ebook-tools
# Date created:		2008-07-13
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ebook-tools
PORTVERSION=	0.2.1
CATEGORIES=	textproc kde
MASTER_SITES=	SF

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessing and converting various ebook file formats

LIB_DEPENDS=	zip.1:${PORTSDIR}/archivers/libzip

USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	libxml2 pkgconfig

.include <bsd.port.mk>
