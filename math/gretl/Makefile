# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	1.9.4
CATEGORIES=	math finance
MASTER_SITES=	SF

MAINTAINER=	bf@FreeBSD.org
COMMENT=	GNU Regression, Econometrics and Time-series Library

LIB_DEPENDS=	fftw3.5:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WANT_GNOME=	yes

ALL_TARGET=	# empty
CONFIGURE_ARGS =	--enable-static --enable-shared --with-gmake --without-gnome
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" \
			LAPACK_LIBS="${LAPACK} ${BLAS}" \
			LDFLAGS="${LDFLAGS}"

MAN1=		gretl.1
OPTIONS=	ATLAS "Use Atlas for BLAS and LAPACK" off \
		GUI "Build the graphical user interface and plugins" on \
		NLS "Build with Natural Language Support" on \
		ODBC "Build with unixODBC database support" off \
		R "Build with libR support" off \
		SSE2 "Enable build-time auto-detection of SSE2 on i386 for RNG" off

.include <bsd.port.pre.mk>

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas \
		lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if defined(WITH_GUI)
CONFIGURE_ARGS+=	--enable-gui=yes
USE_GNOME=		gnomehier gtksourceview2
BUILD_DEPENDS+=		gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=		gnuplot:${PORTSDIR}/math/gnuplot
PLIST_SUB+=		GUI=""
.else
CONFIGURE_ARGS+=	--enable-gui=no
PLIST_SUB+=		GUI="@comment "
.endif

.if !defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--enable-nls=yes
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--enable-nls=no
PLIST_SUB+=		NLS="@comment "
.endif

.if defined(WITH_ODBC)
CONFIGURE_ARGS+=	--with-odbc
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
PLIST_SUB+=		ODBC=""
.else
CONFIGURE_ARGS+=	--without-odbc
PLIST_SUB+=		ODBC="@comment "
.endif

.if defined(WITH_R)
CONFIGURE_ARGS+=	--with-libR
LIB_DEPENDS+=		R.0:${PORTSDIR}/math/R
.else
CONFIGURE_ARGS+=	--without-libR
.endif

.if ${ARCH} == "amd64" || (${ARCH} == "i386" && defined(WITH_SSE2))
CONFIGURE_ARGS+=	--enable-sse2=yes
.else
CONFIGURE_ARGS+=	--enable-sse2=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|set term png|set term dumb|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| DOMAIN| CEPHES_DOMAIN|g' \
		${WRKSRC}/cephes/iv.c
	@${REINPLACE_CMD} -e 's|@gnome_prefix@|@prefix@|g' \
		${WRKSRC}/gnome/gretl.keys.in

.if defined(WITH_GUI)
post-install:
	@${MKDIR} ${PREFIX}/share/applications
.for _file in gretl.desktop
	${INSTALL_DATA} ${WRKSRC}/gnome/${_file} ${PREFIX}/share/applications
.endfor
	@${MKDIR} ${PREFIX}/share/mime/packages
.for _file in gretl.xml
	${INSTALL_DATA} ${WRKSRC}/xdg/${_file} ${PREFIX}/share/mime/packages
.endfor
	@${MKDIR} ${PREFIX}/share/mime-info
.for _file in gretl.keys gretl.mime
	${INSTALL_DATA} ${WRKSRC}/gnome/${_file} ${PREFIX}/share/mime-info
.endfor
	@${MKDIR} ${PREFIX}/share/pixmaps
.for _file in gnome-application-x-gretldata.png gnome-application-x-gretlsession.png
	${INSTALL_DATA} ${WRKSRC}/gnome/${_file} ${PREFIX}/share/pixmaps
.endfor
.for _file in gretl-logo.xpm gretl.xpm
	${INSTALL_DATA} ${WRKSRC}/pixmaps/${_file} ${PREFIX}/share/pixmaps
.endfor
	@-update-mime-database ${PREFIX}/share/mime

.endif

regression-test test check: build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
		${MAKE_ARGS} check)

.include <bsd.port.post.mk>
