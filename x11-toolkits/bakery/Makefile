# New ports collection makefile for:	bakery
# Date created:				12th September 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bakery
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A C++ Application Framework for use with Gtkmm

LIB_DEPENDS=	gtkmm-2.0.6:${PORTSDIR}/x11-toolkits/gtk--2 \
		gconfmm-2.0:${PORTSDIR}/devel/gconfmm \
		glademm-2.0:${PORTSDIR}/devel/libglademm \
		xml\\+\\+-1.0:${PORTSDIR}/textproc/libxml++

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack lthack intltool gnometarget
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
