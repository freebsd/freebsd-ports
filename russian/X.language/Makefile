# New ports collection makefile for: X.language
# Version required:     X11R6
# Date created:         31 Aug 1995
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       ru-X11-3.3
CATEGORIES=     russian x11
MASTER_SITES=   http://nagual.pp.ru/~ache/koi8/dist/ \
		ftp://ftp.kiarchive.ru/pub/misc/fonts/cyrillic/xwindows/
DISTFILES=      x6rus-2.3.1-bin.tgz

.if defined(NON_FREE_FONTS)
DISTFILES += Type1.koi8-r.tgz
.else
DISTFILES += Type1.koi8-r.free.tgz
.endif

MAINTAINER=	ache@FreeBSD.org

RUN_DEPENDS=	${X11BASE}/bin/xinit:${PORTSDIR}/x11/XFree86

NO_WRKSUBDIR=   YES
NO_BUILD=       YES
USE_X_PREFIX=   YES

PKGTMP = ${X11BASE}/.Xinstmp
XLIB = ${X11BASE}/lib/X11
CYRF = ${XLIB}/fonts/cyrillic

#Be careful to not delete embedded tab characters
do-install:
	-if [ ! -d ${CYRF}.old ]; then \
		${MV} ${CYRF} ${CYRF}.old; \
	fi
	-${MKDIR} ${CYRF}/100dpi
	-${MKDIR} ${CYRF}/75dpi
	-${MKDIR} ${CYRF}/misc
	cd ${WRKSRC}; \
	${INSTALL_DATA} *.pfb ${XLIB}/fonts/Type1
	cd ${WRKSRC}/cyrillic; \
	${INSTALL_DATA} xrus.info ${CYRF}; \
	for i in 100dpi 75dpi misc; do \
		${INSTALL_DATA} $$i/* ${CYRF}/$$i; \
	done
#       ${INSTALL_DATA} ${FILESDIR}/xmodmap ${XLIB}/xinit/.Xmodmap
	if [ ! -d ${XLIB}/nls ] ; then \
		${MKDIR} ${XLIB}/nls; \
		${CHOWN} ${BINOWN}.${BINGRP} ${XLIB}/nls; \
		${CHMOD} 755 ${XLIB}/nls; \
	fi
	if [ ! -f ${XLIB}/nls/ru_SU.KOI8-R ] ; then \
		${INSTALL_DATA} ${FILESDIR}/nls_koi8-r ${XLIB}/nls/ru_SU.KOI8-R; \
	fi
	if [ ! -f ${XLIB}/nls/C ] ; then \
		${INSTALL_DATA} ${FILESDIR}/nls_C ${XLIB}/nls/C; \
	fi
	${MAKE} pre-package
	${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	${MAKE} post-package

pre-package:
	-${MKDIR} ${PKGTMP}
	cd ${FILESDIR}; \
	$(CP) nls_dir_list nls_alias_list replace_nls_list ${PKGTMP}
	cd ${WRKSRC}; \
	$(CP) fonts.dir-scale.add ${PKGTMP}

post-package:
	${RM} -rf ${PKGTMP}

.include <bsd.port.mk>
