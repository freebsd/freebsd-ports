# New ports collection makefile for: ghemical
# Date created:			May 4, 2003
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=   .tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Ghemical is a computational chemistry software package

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		${LOCALBASE}/lib/libmpqc.a:${PORTSDIR}/science/mpqc
LIB_DEPENDS=	gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea \
		glade-gnome:${PORTSDIR}/devel/libglade

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GTK=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--enable-mpqc

USE_AUTOCONF=	yes
USE_AUTOCONF_VER=	253

pre-configure:
	@cd ${WRKDIR}/${DISTNAME} ; ${AUTOCONF}

pre-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g;' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g; s|-lgtk|-lgtk12|g;' \
			${WRKSRC}/Makefile.in
pre-build:
	@${REINPLACE_CMD} -e 's|f2c.h|g2c.h|g;' ${WRKSRC}/miniMOPAC/*.c
	@${REINPLACE_CMD} -e 's|f2c.h|g2c.h|g;' ${WRKSRC}/src/common/qm1e_mopac.cpp
.include <bsd.port.mk>
