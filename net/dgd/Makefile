# New ports collection makefile for:	dgd
# Version required:	1.0.37
# Date created:		23 August 1994
# Whom:			adam
#
# $Id: Makefile,v 1.35 1996/02/08 00:30:29 adam Exp $
#

DISTNAME=	dgd-1.0.37
CATEGORIES=	net lang
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/

#PATCH_SITES=	ftp.veda.is:/pub/mud/dgd/patches/
#PATCHFILES=	1.0.9-1.0.9.1.gz

MAINTAINER=	adam@veda.is

.ifdef PATCHFILES
.if ${PATCHFILES} != ""
PATCH_PRFX=	${DISTNAME}/
PATCHLEVEL!=	echo ${PATCHFILES} | sed 's/^.*\.\(.*\)\.gz$$/\1/'
PKGNAME=	${DISTNAME}.${PATCHLEVEL}
.endif
.endif
WRKSRC=		${WRKDIR}/dgd/src

pre-patch:
	@ln -fs .. ${WRKSRC}/dgd

post-patch:
	@find -X ${WRKDIR}/dgd -name '*.orig' -print | xargs rm -f

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@sed '/^@srcdir/s|\.|${WRKDIR}/\.|' <${PKGDIR}/PLIST >${WRKDIR}/PLIST

do-install:
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
