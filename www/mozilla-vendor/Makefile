# New ports collection makefile for:	mozilla
# Version required:	M8
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

DISTNAME=	mozilla-source-M8
PKGNAME=	mozilla-M8
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/releases/m8/src/

MAINTAINER=	reg@shale.csir.co.za

LIB_DEPENDS=	IDL.2:${PORTSDIR}/devel/ORBit \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

WRKSRC=		${WRKDIR}/mozilla
USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes
CONFIGURE_ARGS=					\
		--disable-cpp-rtti		\
		--disable-md			\
		--disable-pedantic		\
		--disable-xterm-updates		\
		--enable-cpp-exceptions		\
		--enable-debug			\
		--enable-double-buffer		\
		--enable-editor			\
		--enable-idltool		\
		--enable-mailnews		\
		--enable-optimize		\
		--enable-pics			\
		--enable-tests			\
		--enable-toolkit=gtk		\
		--with-jpeg=${LOCALBASE}	\
		--with-png=${LOCALBASE}
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"	\
		GTK_CONFIG="${GTK_CONFIG}"
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin

do-install:
	${MKDIR} ${PREFIX}/lib/mozilla
	${CHMOD} 755 ${PREFIX}/lib/mozilla
	cd ${WRKSRC}/dist/bin && tar -chf - * | \
		tar -xf - -C ${PREFIX}/lib/mozilla
	${INSTALL_SCRIPT} ${WRKSRC}/mozilla ${PREFIX}/bin
	${TOUCH} ${PREFIX}/lib/mozilla/component.reg
	${CHMOD} 666 ${PREFIX}/lib/mozilla/component.reg

.include <bsd.port.mk>
