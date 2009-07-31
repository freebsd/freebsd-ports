# ports collection makefile for: gimp-print
# Date Created: 2002 01 02
# Whom: dgilbert@velocet.ca
#
# $FreeBSD$
#    $MCom: ports/print/gutenprint-base/Makefile,v 1.8 2007/03/30 16:45:02 ahze Exp $
#

PORTNAME?=	gutenprint
PORTVERSION=	5.1.7
PORTREVISION?=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gimp-print
PKGNAMESUFFIX?=	-base

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GutenPrint Printer Driver

CONFLICTS=	gimp-print-[0-9]*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=--with-gimp=no --with-gimp2=no
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include -I${PREFIX}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${PREFIX}/lib

.include <bsd.port.pre.mk>

.if ${SLAVE_PORT}=="yes"
LIB_DEPENDS+=	gutenprintui2.1:${PORTSDIR}/print/gutenprint-base
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GUTENPRINTUI2_LIBS=`${PKG_CONFIG} --libs gutenprintui2`
.else
MAN1+=		escputil.1
.endif

.if defined(GUT_SLAVE) && (${GUT_SLAVE}=="gimp" || ${GUT_SLAVE}=="gimp-devel")
.if ${GUT_SLAVE}=="gimp"
LIB_DEPENDS+=	gimp-2.0:${PORTSDIR}/graphics/gimp-app
.elif ${GUT_SLAVE}=="gimp-devel"
LIB_DEPENDS+=	gimp-2.0:${PORTSDIR}/graphics/gimp-app-devel
.endif
LIB_DEPENDS+=	gutenprint.2:${PORTSDIR}/print/gutenprint-base
CONFIGURE_ARGS=--with-gimp2=yes # Override CONFIGURE_ARGS
BUILD_WRKSRC=	${WRKSRC}/src/gimp2
INSTALL_WRKSRC=	${WRKSRC}/src/gimp2
.else
CONFIGURE_ARGS+=--without-gimp2
.endif

.if defined(GUT_SLAVE) && ${GUT_SLAVE}=="cups"
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS+=	espgs:${PORTSDIR}/print/cups-pstoraster
CONFIGURE_ARGS+=	--with-cups=${PREFIX} \
			--enable-cups-ppds \
			--enable-cups-level3-ppds
MAN8+=	cups-calibrate.8 cups-genppd.8 cups-genppdconfig.8 \
	cups-genppdupdate.8
BUILD_WRKSRC=	${WRKSRC}/src/cups
INSTALL_WRKSRC=	${WRKSRC}/src/cups
.else
CONFIGURE_ARGS+=	--without-cups
.endif

.if defined(GUT_SLAVE) && ${GUT_SLAVE}=="ijs"
LIB_DEPENDS+=	ijs.1:${PORTSDIR}/print/libijs
CONFIGURE_ARGS+=--with-ijs=yes
MAN1+=		ijsgutenprint.1
BUILD_WRKSRC=	${WRKSRC}/src/ghost
INSTALL_WRKSRC=	${WRKSRC}/src/ghost
.else
CONFIGURE_ARGS+=--without-ghostscript
.endif

.if defined(GUT_SLAVE) && ${GUT_SLAVE}=="foomatic"
BUILD_DEPENDS+=	foomatic-combo-xml:${PORTSDIR}/print/foomatic-db-engine
RUN_DEPENDS+=	foomatic-combo-xml:${PORTSDIR}/print/foomatic-db-engine \
		foomatic-db>0:${PORTSDIR}/print/foomatic-db
CONFIGURE_ARGS+=--with-foomatic=yes --with-foomatic3=yes
BUILD_WRKSRC=	${WRKSRC}/src/foomatic
INSTALL_WRKSRC=	${WRKSRC}/src/foomatic
.else
CONFIGURE_ARGS+=--without-foomatic
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-user-guide=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/lpstat|${LOCALBASE}/bin/lpstat|' \
		${WRKSRC}/src/gutenprintui2/plist.c
.if ${SLAVE_PORT}=="no" || ${GUT_SLAVE}!="cups"
	@${REINPLACE_CMD} -e 's|cups	||' ${WRKSRC}/src/Makefile.in
.endif
.if ${SLAVE_PORT}=="yes"
	@${REINPLACE_CMD} -e 's|= escputil.1|= |' ${WRKSRC}/man/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|%%GUTENPRINTUI2_LIBS%%|${GUTENPRINTUI2_LIBS}|' \
		${WRKSRC}/src/gimp2/Makefile.in
	@${REINPLACE_CMD} -e 's|$$libdir/gimp/1.2/plug-ins||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|= $$(pkglibdir)|= ${PREFIX}/libexec/cups|' \
		${WRKSRC}/src/cups/Makefile.in

post-install:
.if ${SLAVE_PORT}=="yes"
	@(cd ${WRKSRC}/man && ${GMAKE} ${INSTALL_TARGET})
.endif

.include <bsd.port.post.mk>
