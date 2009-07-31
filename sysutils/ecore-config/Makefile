# New ports collection makefile for:	ecore-config
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	config
PORTVERSION=	0.9.9.042
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (config module)

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_EFL=	ecore eet evas
USE_EFL_ECORE=	ipc con
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_config
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS=	--enable-ecore-con \
		--enable-ecore-config \
		--disable-ecore-desktop \
		--disable-ecore-directfb \
		--disable-ecore-evas \
		--disable-ecore-file \
		--enable-ecore-ipc \
		--disable-ecore-job \
		--disable-ecore-sdl \
		--disable-ecore-txt \
		--disable-ecore-x \
		--disable-ecore-imf \
		--disable-ecore-imf_evas

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_ipc/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_con/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_ipc/libecore_ipc\.la,-lecore_ipc,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_con/libecore_con\.la,-lecore_con,'\
		${BUILD_WRKSRC}/Makefile.in ${WRKSRC}/src/bin/Makefile.in
	@${REINPLACE_CMD} -E \
		-e 's,../lib/ecore_ipc/.libs/libecore_ipc.la,-lecore_ipc,g' \
		-e 's,../lib/ecore_con/.libs/libecore_con.la,-lecore_con,g' \
		-e 's,../lib/ecore/.libs/libecore.la,-lecore,g' \
		${WRKSRC}/src/bin/Makefile.in

post-build:
	@(cd ${WRKSRC}/src/bin; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-config.pc \
		${PREFIX}/libdata/pkgconfig/

	@(cd ${WRKSRC}/src/bin; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.mk>
