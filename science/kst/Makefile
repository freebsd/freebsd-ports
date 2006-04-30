# New ports collection makefile for:	kst
# Date created:			Fri Apr 30 17:28:56 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kst
PORTVERSION=	1.2.1
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE} \
		http://omega.astro.utoronto.ca/${PORTNAME}/
MASTER_SITE_SUBDIR=	stable/apps/KDE3.x/scientific

MAINTAINER=	kay_lehmann@web.de
COMMENT=	Data viewing program for KDE

LIB_DEPENDS=	cfitsio.0:${PORTSDIR}/astro/cfitsio \
		gsl.7:${PORTSDIR}/math/gsl

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
USE_GETTEXT=	yes

OPTIONS=	NETCDF "Enable netcdf file support" off \
		CDF "Enable cdf file support" off

MAN1=		kst.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

.if defined(WITH_NETCDF)
LIB_DEPENDS+=	netcdf.1:${PORTSDIR}/science/netcdf
PLIST_SUB+=	NETCDF=""
.else
CONFIGURE_ARGS+=	--without-netcdf
PLIST_SUB+=	NETCDF="@comment "
.endif

.if defined(WITH_CDF)
LIB_DEPENDS+=	cdf.0:${PORTSDIR}/science/cdf
PLIST_SUB+=	CDF=""
.else
CONFIGURE_ARGS+=	--without-cdf
PLIST_SUB+=	CDF="@comment "
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/kst/kst/ksttimers.h.in
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.if !defined(WITH_NETCDF)
	@${REINPLACE_CMD} -e 's| netcdf||g' ${WRKSRC}/kst/kst/datasources/Makefile.in
.endif
.if !defined(WITH_CDF)
	@${REINPLACE_CMD} -e 's| cdf||g' ${WRKSRC}/kst/kst/datasources/Makefile.in
.endif

.include <bsd.port.post.mk>
