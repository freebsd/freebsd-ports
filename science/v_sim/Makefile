# New ports collection makefile for:	V_Sim
# Date created:			Sep 27, 2005
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=	v_sim
PORTVERSION=	3.3.0
PORTREVERSION=	1
CATEGORIES=	science
MASTER_SITES=	http://www-drfmc.cea.fr/sp2m/L_Sim/V_Sim/download/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Visualization of atomic structures

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if !defined(WITHOUT_CDF)
LIB_DEPENDS+=	netcdf.4:${PORTSDIR}/science/netcdf
CONFIGURE_ARGS+=--with-nanoquanta --with-nanoquanta-path=${LOCALBASE}
PLIST_SUB+=	CDF=""
.else
CONFIGURE_ARGS+=--without-nanoquanta
PLIST_SUB+=	CDF="@comment "
.endif

.if !defined(WITHOUT_BABEL)
LIB_DEPENDS+=	openbabel.1:${PORTSDIR}/science/openbabel
CONFIGURE_ARGS+=--with-openbabel --with-openbabel-path=${LOCALBASE}
PLIST_SUB+=	BABEL=""
.else
CONFIGURE_ARGS+=--without-openbabel
PLIST_SUB+=	BABEL="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|$$datadir/doc/$$PACKAGE/examples|${EXAMPLESDIR}|'	\
		-e 's|CFLAGS="-O2"|#CFLAGS="-O2"|;s|Werror ansi pedantic-errors||'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's|-pedantic-errors||' \
	    	${WRKSRC}/src/extraGtkFunctions/Makefile.in
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's|etc 	po 	Documentation|etc 	Documentation|'	\
		${WRKSRC}/Makefile.in
.endif
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|Documentation 	pixmaps 	examples|pixmaps|'	\
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
