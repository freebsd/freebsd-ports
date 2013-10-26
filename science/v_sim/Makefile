# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	v_sim
PORTVERSION=	3.6.1.1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://www-drfmc.cea.fr/sp2m/L_Sim/V_Sim/download/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Visualization of atomic structures

LICENSE=	CeCILL
LICENSE_NAME=	CeCILL
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_FORTRAN=	yes
USE_GNOME=	gtk20
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	${CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
MAN1=		v_sim.1
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_CDF)
LIB_DEPENDS+=	netcdf.4:${PORTSDIR}/science/netcdf
CONFIGURE_ARGS+=--with-netcdf=${LOCALBASE}
PLIST_SUB+=	CDF=""
.else
CONFIGURE_ARGS+=--without-netcdf
PLIST_SUB+=	CDF="@comment "
.endif

.if !defined(WITHOUT_BABEL)
LIB_DEPENDS+=	openbabel:${PORTSDIR}/science/openbabel
CONFIGURE_ARGS+=--with-openbabel
PLIST_SUB+=	BABEL=""
.else
CONFIGURE_ARGS+=--without-openbabel
PLIST_SUB+=	BABEL="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|$$datadir/doc/$$PACKAGE/examples|${EXAMPLESDIR}|'	\
		-e 's|CFLAGS="-O2"|#CFLAGS="-O2"|;s|Werror ansi pedantic-errors||'	\
		-e 's|$${docdir}/examples|${EXAMPLESDIR}|'				\
		${WRKSRC}/${CONFIGURE_SCRIPT}
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e 's|	po ||'	\
		${WRKSRC}/Makefile.in
.endif
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|Documentation||'	\
		${WRKSRC}/Makefile.in
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e 's|pixmaps \\|pixmaps|;s|examples$$||'	\
		${WRKSRC}/Makefile.in
	${FIND} ${WRKSRC}/lib/plug-ins -name Makefile.in | ${XARGS} \
	${REINPLACE_CMD} -e	\
	's|install-v_simexamplesDATA install-v_simpixmapsDATA|install-v_simpixmapsDATA|'
	${REINPLACE_CMD} -e 's|: install-v_simexamplesDATA|:|'	\
		${WRKSRC}/lib/python/Makefile.in
.endif

.include <bsd.port.mk>
