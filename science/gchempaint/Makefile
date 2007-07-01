# New ports collection makefile for:	gchempaint
# Date created:			Mar 18, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	gchempaint
PORTVERSION=	0.8.1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/0.8

MAINTAINER=	pav@FreeBSD.org
COMMENT=	2D chemical structures editor for GNOME 2

BUILD_DEPENDS=	gnome-doc-prepare:${PORTSDIR}/textproc/gnome-doc-utils
LIB_DEPENDS=	gcu.8:${PORTSDIR}/science/gchemutils

USE_BZIP2=	yes
USE_XLIB=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	gchempaint.schemas gchempaint-arrows.schemas
USE_GNOME=	gnomehack intlhack libgnomeprintui libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-help-dir=${PREFIX}/share/gnome/help --with-omf-dir=${PREFIX}/share/gnome/omf

post-patch:
	@${REINPLACE_CMD} -e 's|-release $$(VERSION)|-version @GCP_VERSION_INFO@|' \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/libgcpcanvas/Makefile.in
	@${REINPLACE_CMD} -e 's,GNOME|Applications|Education,Applications|Education,' ${WRKSRC}/help/gchempaint.omf.in

.include <bsd.port.mk>
