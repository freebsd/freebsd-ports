# New ports collection makefile for: X.language
# Date created:         31 Aug 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	X11
PORTVERSION=	3.3
CATEGORIES=	russian x11
MASTER_SITES=	http://koi8.pp.ru/dist/ \
		ftp://ftp.kiarchive.ru/pub/misc/fonts/cyrillic/xwindows/
DISTFILES=	x6rus-2.3.1-bin.tgz

.if defined(NON_FREE_FONTS)
DISTFILES+=	Type1.koi8-r.tgz
.else
DISTFILES+=	Type1.koi8-r.free.tgz
.endif

MAINTAINER=	ache@FreeBSD.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes

PKGTMP=		${X11BASE}/.Xinstmp
XLIB=		${X11BASE}/lib/X11
CYRF=		${XLIB}/fonts/cyrillic

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
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
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
