# ex:ts=8
# Ports collection makefile for:	gtkmathview
# Date created:			Oct 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkmathview
PORTVERSION=	0.7.7
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://helm.cs.unibo.it/mml-widget/sources/

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A GTK Widget to Render MathML Documents

LIB_DEPENDS=	t1:${PORTSDIR}/devel/t1lib \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gmetadom_gdome_cpp_smart:${PORTSDIR}/textproc/gmetadom \
		popt.0:${PORTSDIR}/devel/popt \
		xslt.2:${PORTSDIR}/textproc/libxslt

USE_ICONV=	yes
USE_GNOME=	glib20 gtk20 gnomehack
USE_AUTOTOOLS=	libtool:15
CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=	mathmlviewer.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=	is unsupported on versions prior to FreeBSD 6.0
.endif

.include <bsd.port.post.mk>
