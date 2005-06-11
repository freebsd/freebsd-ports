# New ports collection makefile for:   gtkmm2
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gtkmm
PORTVERSION=	2.6.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R} \
		gtkmm
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+, Pango, Atk

LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

LATEST_LINK=	gtkmm24

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
USE_INC_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gtk20
CONFIGURE_ARGS=	--enable-static=yes \
		--with-sigc-prefix=${LOCALBASE}

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

.if defined(WITH_EXAMPLES)
CONFIGURE_ARGS+=--enable-examples
PLIST_SUB+=	EXAMPLES=""
.else
CONFIGURE_ARGS+=--disable-examples
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		-e '/^SUBDIRS =/s/@DEMO_SUBDIR@//' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/docs//' \
		${WRKSRC}/Makefile.in
.endif

patch-autotools:
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

.include <bsd.port.mk>
