# ex:ts=8
# Ports collection makefile for:	gtkmathview
# Date created:			Oct 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkmathview
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A GTK Widget to Render MathML Documents

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		t1:${PORTSDIR}/devel/t1lib \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gmetadom_gdome_cpp_smart:${PORTSDIR}/textproc/gmetadom

USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
USE_X_PREFIX=	yes
USE_GNOME=	glib20 gtk20 gnomehack
USE_LIBTOOL_VER=13
CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	mathmlviewer.1 mathml2ps.1

post-patch:
.for file in src/stringAux.cc src/PS_T1_FontManager.cc
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
