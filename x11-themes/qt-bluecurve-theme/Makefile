# New ports collection makefile for:    bluecurve-unified
# Date created:         3 October 2002
# Whom:                 Eugeney Ryzhyk
#
# $FreeBSD$
#

PORTNAME=	qt-bluecurve-theme
PORTVERSION=	0.88
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	fedora/fedora/1/i386/SRPMS.os
DISTFILES=	redhat-artwork-${PORTVERSION}-${RH_SUBVERSION}.src.rpm

MAINTAINER=	rzheka@users.sourceforge.net
COMMENT=	Bluecurve unified-look theme for QT3 from Fedora

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

WRKSRC= 	${WRKDIR}/redhat-artwork-${PORTVERSION}
USE_LIBTOOL_VER=13
#LIBTOOLFILES=	# none
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

RH_SUBVERSION=	1

USE_QT_VER=	3
THEMES_SUBDIRS =	${WRKSRC}/art/qt/Bluecurve

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && rpm2cpio.pl ${_DISTDIR}/${DISTFILES} | cpio -i redhat-artwork-${PORTVERSION}.tar.gz 2>/dev/null && ${GZIP_CMD} -dc redhat-artwork-${PORTVERSION}.tar.gz | tar -xf - && ${RM} redhat-artwork-${PORTVERSION}.tar.gz);\
		then \
			exit 1; \
		fi
	${CP} ${FILESDIR}/Makefile-qt3 ${WRKSRC}/art/qt/Bluecurve/Makefile

# There's no configure script, but we need libtool to build
do-configure:
	@${DO_NADA}

post-patch:
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#' ${WRKSRC}/art/qt/Bluecurve/Makefile
	@${RM} ${THEMES_SUBDIRS}/bluecurve.moc

do-build:
	@for theme_dir in ${THEMES_SUBDIRS};do \
		(cd $$theme_dir; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}); \
	done
do-install:
	@${MKDIR} ${PREFIX}/lib/plugins/styles && ${CHMOD} a+rx ${PREFIX}/lib/plugins/styles
	@${INSTALL_PROGRAM} ${WRKSRC}/art/qt/Bluecurve/.libs/bluecurve.so ${PREFIX}/lib/plugins/styles

.include <bsd.port.mk>
