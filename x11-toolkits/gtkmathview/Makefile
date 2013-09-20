# Created by: ijliao
# $FreeBSD$

PORTNAME=	gtkmathview
PORTVERSION=	0.8.0
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK Widget to Render MathML Documents

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		t1:${PORTSDIR}/devel/t1lib \
		gmetadom_gdome_cpp_smart:${PORTSDIR}/textproc/gmetadom

USES=		pathfix pkgconfig
USE_GNOME=	gtk20 libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

MAN1=		mathmlviewer.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
