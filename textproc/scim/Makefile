# New ports collection makefile for:    scim
# Date created:		20 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim
PORTVERSION=	0.99.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://freedesktop.org/~suzhe/sources/
MASTER_SITE_SUBDIR=scim
MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	Smart Common Input Method platform

USE_GNOME=	gtk20 gconf2 lthack

USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+= ${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=   ${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+= CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/stlport" \
                LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc -lintl ${PTHREAD_LIBS}"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-4-stable
PLIST_SUB=	NOSTABLE="@comment "
.else
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
PLIST_SUB=	NOSTABLE=""
.endif

post-configure:
	${REINPLACE_CMD} '/^pkgconfigdir/s|$$(libdir)|$${exec_prefix}/libdata|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} '/^scim_setup_LDFLAGS/s|=|= ${PTHREAD_LIBS}|g' \
		${WRKSRC}/extras/setup/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type make post-install

.include <bsd.port.post.mk>
