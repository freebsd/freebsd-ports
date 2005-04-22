# New ports collection makefile for:	libgnomeprintuimm
# Date created:				17 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomeprintuimm
PORTVERSION=	2.5.2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.5
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrappers for the GNOME print support library

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gnomeprintmm-2.5.2:${PORTSDIR}/print/libgnomeprintmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeprintui
USE_GCC=	3.4
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=15
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.5" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e 's|2\.0|2.6|' ${WRKSRC}/tools/m4/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

patch-autotools:
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

.include <bsd.port.mk>
