# New ports collection makefile for:	V_Sim
# Date created:			Sep 27, 2005
# Whom:				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$

PORTNAME=	v_sim
PORTVERSION=	3.1.2
CATEGORIES=	science
MASTER_SITES=	http://www-drfmc.cea.fr/sp2m/L_Sim/V_Sim/download/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Visualization of atomic structures

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include"	\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
USE_GCC=	3.4+

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/gtkdoc-mkdb) || defined(WITH_FULL_DOC)
BUILD_DEPENDS+=	gtkdoc-mkdb:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+="--enable-gtk-doc"
PLIST_SUB+=	REFDOC=""
.else
CONFIGURE_ARGS+="--disable-gtk-doc"
PLIST_SUB+=	REFDOC="@comment "
.endif

.if ${OSVERSION} < 500000
BROKEN=		"does not compile with gcc 2.95"
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|$$datadir/doc/$$PACKAGE/examples|${EXAMPLESDIR}|'	\
		-e 's|CFLAGS="-O2"|#CFLAGS="-O2"|'					\
		${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/src/Makefile.in
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's|etc 	po 	Documentation|etc 	Documentation|'	\
		${WRKSRC}/Makefile.in
.endif
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|Documentation 	pixmaps 	examples|pixmaps|'	\
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
