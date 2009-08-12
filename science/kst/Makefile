# New ports collection makefile for:	kst
# Date created:			Fri Apr 30 17:28:56 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kst
PORTVERSION=	1.8.0
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE3.x/scientific

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data viewing program for KDE

BUILD_DEPENDS=	${LOCALBASE}/lib/libmuparser.a:${PORTSDIR}/math/muparser
LIB_DEPENDS=	cfitsio.0:${PORTSDIR}/astro/cfitsio \
		gsl.13:${PORTSDIR}/math/gsl

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	NETCDF "Enable netcdf file support" off \
		CDF "Enable cdf file support" off

MAN1=		kst.1

.include <bsd.port.pre.mk>

.if defined(WITH_NETCDF)
LIB_DEPENDS+=	netcdf.4:${PORTSDIR}/science/netcdf
PLIST_SUB+=	NETCDF=""
.else
CONFIGURE_ARGS+=	--without-netcdf
PLIST_SUB+=	NETCDF="@comment "
.endif

.if defined(WITH_CDF)
CONFIGURE_ARGS+=LDFLAGS="-lm"
LIB_DEPENDS+=	cdf.0:${PORTSDIR}/science/cdf
PLIST_SUB+=	CDF=""
.else
CONFIGURE_ARGS+=	--without-cdf
PLIST_SUB+=	CDF="@comment "
.endif

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${SH} admin/cvs.sh dist)
	@${REINPLACE_CMD} -e 's|@kde_widgetdir@|@prefix@/lib/kde3/plugins/designer|' \
		${WRKSRC}/kst/src/widgets/Makefile.in
.if !defined(WITH_NETCDF)
	@${REINPLACE_CMD} -e 's| netcdf||g' ${WRKSRC}/kst/src/datasources/Makefile.in
.endif
.if !defined(WITH_CDF)
	@${REINPLACE_CMD} -e 's| cdf||g' ${WRKSRC}/kst/src/datasources/Makefile.in
.endif

.include <bsd.port.post.mk>
