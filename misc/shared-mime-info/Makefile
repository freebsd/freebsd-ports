# New ports collection makefile for:	shared-mime-info
# Date created:        31 May 2002
# Whom:                olgeni@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	shared-mime-info
PORTVERSION=	0.12
CATEGORIES=	misc
MASTER_SITES=	http://www.freedesktop.org/software/shared-mime-info/releases/
DISTNAME=	shared-mime-info-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A MIME type database from the FreeDesktop project

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		glib-2.0.200:${PORTSDIR}/devel/glib20

GNU_CONFIGURE=	yes

MAN1=		update-mime-database.1

.include <bsd.port.mk>
