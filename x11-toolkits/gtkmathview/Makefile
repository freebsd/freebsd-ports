# ex:ts=8
# Ports collection makefile for:	gtkmathview
# Date created:			Oct 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkmathview
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK Widget to Render MathML Documents

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		t1:${PORTSDIR}/devel/t1lib \
		gmetadom_gdome_cpp_smart:${PORTSDIR}/textproc/gmetadom

USE_GNOME=	gnomehack gtk20 libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=		mathmlviewer.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
