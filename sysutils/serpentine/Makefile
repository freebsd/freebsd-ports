# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/sysutils/serpentine/Makefile,v 1.4 2006/08/31 05:21:45 marcus Exp $

PORTNAME=	serpentine
PORTVERSION=	0.7
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome Audio Cd Burner

BUILD_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		pkgconfig gmake python tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	pygnomedesktop intlhack
USE_GSTREAMER=	core gnomevfs python

.include <bsd.port.mk>
