# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kst
PORTVERSION=	1.9.1
PORTREVISION=	5
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE3.x/scientific

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Data viewing program for KDE

BUILD_DEPENDS=	${LOCALBASE}/lib/libmuparser.a:${PORTSDIR}/math/muparser
LIB_DEPENDS=	cfitsio:${PORTSDIR}/astro/cfitsio \
		gsl:${PORTSDIR}/math/gsl

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:env autoconf:env libtool
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

AUTOTOOLSFILES=	admin/cvs.sh

OPTIONS_DEFINE=	NETCDF CDF KDEBASE
CDF_DESC=	CDF data support
KDEBASE_DESC=	JavaScript console

MAN1=		kst.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=	netcdf:${PORTSDIR}/science/netcdf
PLIST_SUB+=	NETCDF=""
.else
CONFIGURE_ARGS+=	--without-netcdf
PLIST_SUB+=	NETCDF="@comment "
.endif

.if ${PORT_OPTIONS:MCDF}
CONFIGURE_ARGS+=LDFLAGS="-lm"
LIB_DEPENDS+=	cdf:${PORTSDIR}/science/cdf
PLIST_SUB+=	CDF=""
.else
CONFIGURE_ARGS+=	--without-cdf
PLIST_SUB+=	CDF="@comment "
.endif

.if ${PORT_OPTIONS:MKDEBASE}
RUN_DEPENDS+=	${KDE_PREFIX}/lib/kde3/libkonsolepart.so:${PORTSDIR}/x11/kdebase3
.endif

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${SH} admin/cvs.sh dist)
	@${REINPLACE_CMD} -e 's|@kde_widgetdir@|@prefix@/lib/kde3/plugins/designer|' \
		${WRKSRC}/kst/src/widgets/Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|et||;/^SUBDIRS/s|pt||' ${WRKSRC}/doc/Makefile.in
.if empty(PORT_OPTIONS:MNETCDF)
	@${REINPLACE_CMD} -e 's| netcdf||g' ${WRKSRC}/kst/src/datasources/Makefile.in
.endif
.if empty(PORT_OPTIONS:MCDF)
	@${REINPLACE_CMD} -e 's| cdf||g' ${WRKSRC}/kst/src/datasources/Makefile.in
.endif

.include <bsd.port.mk>
