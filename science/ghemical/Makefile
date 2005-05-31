# New ports collection makefile for: ghemical
# Date created:			May 4, 2003
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ghemical
PORTVERSION=	1.01
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Ghemical is a computational chemistry software package

BUILD_DEPENDS=	${LOCALBASE}/lib/libmpqc.a:${PORTSDIR}/science/mpqc \
		f2c:${PORTSDIR}/lang/f2c
LIB_DEPENDS=	glut:${PORTSDIR}/graphics/libglut \
		gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea \
		glade-gnome:${PORTSDIR}/devel/libglade

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mpqc

USE_AUTOCONF_VER=	253

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKDIR}/${DISTNAME} ; ${AUTOCONF}

pre-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g;' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g; s|-lgtk|-lgtk12|g;' \
			${WRKSRC}/Makefile.in
pre-build:
	@${REINPLACE_CMD} -e 's|MAXHEV=60, MAXLIT=60|MAXHEV=90, MAXLIT=90|g;' \
		${WRKSRC}/miniMOPAC/fortran/SIZES
	(cd ${WRKSRC}/miniMOPAC ; ${SH} ${FILESDIR}/ghemical-f2c.sh)
	@${REINPLACE_CMD} -e 's|f2c.h|g2c.h|g;' ${WRKSRC}/miniMOPAC/*.c
	@${REINPLACE_CMD} -e 's|f2c.h|g2c.h|g;' ${WRKSRC}/src/common/qm1e_mopac.cpp
.include <bsd.port.post.mk>
