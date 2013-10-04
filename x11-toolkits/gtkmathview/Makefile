# Created by: ijliao
# $FreeBSD$

PORTNAME=	gtkmathview
PORTVERSION=	0.8.0
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK Widget to Render MathML Documents

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libt1.so:${PORTSDIR}/devel/t1lib \
		libgmetadom_gdome_cpp_smart.so:${PORTSDIR}/textproc/gmetadom

USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20 libxml2 pangox-compat
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
