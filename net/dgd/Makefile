# New ports collection makefile for:	dgd
# Version required:	1.0.37
# Date created:		23 August 1994
# Whom:			adam
#
# $Id: Makefile,v 1.42 1996/05/26 17:17:26 adam Exp $
#

DISTNAME=	dgd-1.0.56
DISTFILES=	dgd-1.0.37.tar.gz
CATEGORIES=	net lang
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/

PATCH_SITES=	ftp.veda.is:/pub/mud/dgd/patches/
PATCHFILES=	1.0.37-1.0.38.gz \
		1.0.38-1.0.39.gz \
		1.0.39-1.0.40.gz \
		1.0.40-1.0.41.gz \
		1.0.41-1.0.42.gz \
		1.0.42-1.0.43.gz \
		1.0.43-1.0.44.gz \
		1.0.44-1.0.45.gz \
		1.0.45-1.0.46.gz \
		1.0.46-1.0.47.gz \
		1.0.47-1.0.48.gz \
		1.0.48-1.0.49.gz \
		1.0.49-1.0.50.gz \
		1.0.50-1.0.51.gz \
		1.0.51-1.0.52.gz \
		1.0.52-1.0.53.gz \
		1.0.53-1.0.54.gz \
		1.0.54-1.0.55.gz \
		1.0.55-1.0.56.gz

MAINTAINER=	adam@veda.is

DIST_SUBDIR=	dgd
WRKSRC=		${WRKDIR}/dgd/src

pre-patch:
	@ln -fs .. ${WRKSRC}/dgd

post-patch:
	@find -X ${WRKDIR}/dgd -name '*.orig' -print | xargs rm -f

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@sed '/^@srcdir/s|\.|${WRKDIR}/\.|' <${PKGDIR}/PLIST >${WRKDIR}/PLIST
	@chmod o+r ${WRKDIR}/dgd/doc/kfun/*

do-install:
	@-mv ${PREFIX}/dgd/bin/driver ${PREFIX}/dgd/bin/driver.old
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' pkg/PLIST` \
		| tar -C ${PREFIX} -xpf -

.if !defined(DO_PACKAGE)
package:
#	@${MAKE} ${.MAKEFLAGS} 'PKG_CMD= cd ${WRKDIR}; ${PKG_CMD}' \
	@${MAKE} ${.MAKEFLAGS} 'PKG_ARGS= ${PKG_ARGS} -f ${WRKDIR}/PLIST' \
	    NO_INSTALL= DO_PACKAGE= package
.else
post-package:
	@rm ${INSTALL_COOKIE}
.endif

.include <bsd.port.mk>
