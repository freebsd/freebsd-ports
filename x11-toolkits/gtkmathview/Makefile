# ex:ts=8
# Ports collection makefile for:	gtkmathview
# Date created:			Oct 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkmathview
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK Widget to Render MathML Documents

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		t1:${PORTSDIR}/devel/t1lib \
		xml2:${PORTSDIR}/textproc/libxml2 \
		gmetadom_gdome_cpp_smart:${PORTSDIR}/textproc/gmetadom

BROKEN=		"Configure fails"

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	glib12 gtk12
USE_LIBTOOL=	yes
CPPFLAGS=	-D__GNU_LIBRARY__ -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lm
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	mathmlviewer.1 mathml2ps.1

post-patch:
.for file in src/stringAux.cc src/PS_T1_FontManager.cc
	@${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/${file}
.endfor

post-install:
	@install-info ${PREFIX}/info/gtkmathview.info ${PREFIX}/info/dir

.include <bsd.port.mk>
